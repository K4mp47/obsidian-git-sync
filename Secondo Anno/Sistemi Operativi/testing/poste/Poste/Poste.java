import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.JPanel;

import java.util.Random;

final public class Poste
{
    JFrame frame;
    DrawPanel drawPanel;

    private final Color DARK_RED = new Color(204,0,0);
    private final Color DARK_GREEN = new Color(0,153,0);

    private final Color[] colors = {Color.GREEN,Color.BLACK,Color.BLUE};
    // Dimension of the panel
    private final int X = 500;
    private final int Y = 300;

    // position of counters in the office
    private final int X_COUNTER = 460;
    private final int X_QUEUE   = 300;

    // dimension of the position square
    private final int Xpos = 20;
    private final int Ypos = 20;
    private final int Y_QUEUE   = (Y/Ypos/2)*Ypos;

    private final int N_PERSONS = 50;  // Number of person threads
    private final int N_COUNTERS = 6;  // Number of counters

    private final int SLEEP_PERSON = 500;
    private final int SLEEPSPEED = 100;
    private final int SLEEP_SERVICE = 2000;

    private boolean[] occupied = new boolean[N_COUNTERS]; //occupied counters 
    private Person[] person = new Person[N_PERSONS]; // Array for person threads

    private CodaPoste p = new CodaPoste(X/Xpos+1,Y/Ypos+1,N_COUNTERS); // Monitor

    public static void main(String... args) throws InterruptedException
    {
        new Poste().go();
    }

    private int counterPosition(int id) {
        return  Y/(N_COUNTERS+1)*(id+1)/Ypos*Ypos;
    }

    private void go () throws InterruptedException 
    {        
        frame = new JFrame("Test");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        drawPanel = new DrawPanel();
        drawPanel.setPreferredSize(new Dimension(X, Y));
        frame.getContentPane().add(BorderLayout.CENTER, drawPanel);
        frame.pack();
        frame.setResizable(false);
        // frame.setSize(300, 330);
        frame.setLocationByPlatform(true);
        frame.setVisible(true);

        // Starts person threads
        for (int i=0; i<N_PERSONS; i++) {
            person[i] = new Person(i);
            person[i].start();
        }
        new Show().start();

        for (int i=0; i<N_PERSONS; i++) {
            person[i].join();
            //System.out.println("Terminata "+i);
        }

        boolean failure = false;
        for(int i=0;i<N_PERSONS;i++) {
            if (person[i].accident) {
                System.out.println(">>> Persona "+i+" ha calpestato qualcuno!");
                failure = true;
            }
        }
        for(int i=0;i<N_PERSONS;i++) {
            if (person[i].queueviolation) {
                System.out.println(">>> Persona "+i+" ha violato la coda!");
                failure = true;
            }
        }
        if (!failure) {
            System.out.println("Tutte le persone sono uscite correttamente!");
            System.exit(0);
        } else {
            System.exit(1);
        }

    }

    class DrawPanel extends JPanel
    {
        private static final long serialVersionUID = 1L;

        private void drawPerson(int x, int y, boolean accident, Graphics g, Color c) {
            if(x >=0 && y >=0) {
                if (accident)
                    g.setColor(Color.RED);
                else
                    g.setColor(c);

                g.fillOval(x, y-5, 20, 10);
            }
        }

        private void drawCounter(int x, int y, Graphics g, int id) {
            synchronized(p) {
                if (occupied[id]) {
                    g.setColor(DARK_RED);
                } else {
                    g.setColor(DARK_GREEN);
                }
            }
            g.fillRect(x, y-6,20, 2);
            g.fillRect(x, y+6,20, 2);
            g.fillRect(x, y-6, 2,12);
        }
        public void paintComponent(Graphics g)
        {
            g.setColor(Color.BLUE);
            g.fillRect(0, 0, this.getWidth(), this.getHeight());
            g.setColor(Color.RED);
            g.fillRect(3, 3, this.getWidth() - 6, this.getHeight() - 6);
            g.setColor(Color.WHITE);
            g.fillRect(6, 6, this.getWidth() - 12, this.getHeight() - 12);
            g.setColor(Color.BLACK);
            
            g.fillRect(Xpos, Y_QUEUE-10,X_QUEUE, 2);
            g.fillRect(Xpos, Y_QUEUE+10,X_QUEUE, 2);

            for(int i=0;i<N_COUNTERS;i++) this.drawCounter(X_COUNTER,counterPosition(i),g,i);
            // System.out.println(" " + this.getWidth() + " " + this.getHeight());
            for(int i=0;i<N_PERSONS;i++) {
                try {
                    this.drawPerson(person[i].getX(),person[i].getY(),person[i].accident,g,person[i].color);
                } catch (NullPointerException e) {
                }
            }
        }
    }

    class Person extends Thread {
        int id;
        int x=-1;
        int y=-1;
        int newx, newy;
        int counter;
        int speed;
        public Color color;
        public boolean accident = false;
        public boolean queueviolation = false;

        Random rand = new Random();

        Person(int id) {
            this.id = id;
        }

        private boolean checkAccident() {
            for(int i=0;i<N_PERSONS;i++) {
                if (i == id) continue;
                try {
                    if (person[i].getX() == newx && person[i].getY() == newy) {
                        System.out.println("Calpestamento tra "+id+" e "+i+"!");
                        accident=true;
                        person[i].accident=true;
                        return true;
                    }
                } catch (NullPointerException e) {
                }
            }
            return false;
        }

        private void pausePerson() throws InterruptedException{
            sleep(SLEEP_PERSON-speed);
        }

        public void run() {
            try {
                go();
            } catch (InterruptedException e) {
                System.out.println("Persona "+id+ " interrotta!");
            }
        }

        private boolean moveto(int fx, int fy) throws InterruptedException{
            while( x != fx || y != fy ) {
                if (accident) return false; // exits if someone else crashed into me
                
                // move
                newx=x;
                if (x != fx) newx+= (x < fx) ? Xpos : -Xpos;
                newy=y;
                if (y != fy) newy+= (y < fy) ? Ypos : -Ypos;

                synchronized(p) {
                    p.move(x/Xpos,y/Ypos,newx/Xpos,newy/Ypos);
                    if (checkAccident()) return false; // should be prevented by move
                    x = newx; y = newy;
                }
                pausePerson();            
            }
            return true;
        }

        private void go() throws InterruptedException {
            //System.out.println("Hey Person "+id);
            sleep((long)(SLEEP_PERSON*id*1.5));

            x = 0;
            y = Y_QUEUE;
            int counter;
            speed = rand.nextInt(SLEEPSPEED);

            color = colors[rand.nextInt(3)];

            if (!moveto(X_QUEUE,y))
                return; // exits if someone else crashed into me

            counter = p.attendiSportello(); // waits for a free counter

            synchronized(p) {
                if (occupied[counter]) {
                    System.out.println("Sportello già occupato: "+counter);
                    color = Color.RED;
                    queueviolation = true;
                    // return;
                }
                occupied[counter] = true;
            }

            if (!moveto(X_COUNTER-Xpos,counterPosition(counter)))
                return; // exits if someone else crashed into me


            sleep(SLEEP_SERVICE);
            synchronized(p) {
                occupied[counter] = false;
            }
            p.liberaSportello(counter);


            if (!moveto(x,y-Ypos))
                return; // exits if someone else crashed into me

            if (!moveto(X,y))
                return; // exits if someone else crashed into me
          
            p.libera(x/Xpos,y/Ypos);
            x = -1;
            //System.out.println("Done Person "+id + " "+y+" "+counter);

        }
        public int getX() { return x; }
        public int getY() { return y; }
    }

    class Show extends Thread { 
        public void run() {
            while(true) {
                frame.repaint();
                try {
                    sleep(100);
                } catch (InterruptedException e) {
                    System.out.println("Interrupted show?? ");
                }   
            }
        }
    }
}


