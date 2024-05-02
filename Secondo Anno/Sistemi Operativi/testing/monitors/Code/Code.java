import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.JPanel;

import java.util.Random;

final public class Code
{
    JFrame frame;
    DrawPanel drawPanel;

    private final Color DARK_RED = new Color(204,0,0);
    private final Color DARK_GREEN = new Color(0,153,0);

    private final Color[] colors = {Color.GREEN,Color.BLUE};
    // Dimension of the panel
    private final int X = 500;
    private final int Y = 350;

    // position of counters in the office
    private final int X_COUNTER = 460;
    private final int X_QUEUE   = 360;

    // dimension of the position square
    private final int Xpos = 20;
    private final int Ypos = 20;
    private final int Y_QUEUE   = (Y/Ypos/2)*Ypos;

    private final int N_PERSONS = 20;  // Number of person threads
    private final int N_COUNTERS = 1;  // Number of counters
    private final int N_QUEUES = 2;    // Number of queues

    private final int SLEEP_PERSON = 500;
    private final int SLEEPSPEED = 50;
    private final int SLEEP_SERVICE = 500;
    private final double SLEEP_GAP = 2;

    private int[] occupied = new int[N_COUNTERS]; //occupied counters 
    private boolean priority_waiting = false; //priority is waiting
    private Person[] person = new Person[N_PERSONS]; // Array for person threads

    private CodeMonitor p = new CodeMonitor(); // Monitor da realizzare
    private SpazioMonitor s = new SpazioMonitor(X/Xpos+1,Y/Ypos+1); //  Monitor spazio

    public static void main(String... args) throws InterruptedException
    {
        new Code().go();
    }

    private int counterPosition(int id) {
        return  Y/(N_COUNTERS+1)*(id+1)/Ypos*Ypos;
    }

    private int queuePosition(int id) {
        return  Y/(N_QUEUES+1)*(id+1)/Ypos*Ypos;
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
        for(int i=0;i<N_PERSONS;i++) {
            if (person[i].priorityviolation) {
                System.out.println(">>> Persona "+i+" ha violato la priorità!");
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
                if (occupied[id] > 1) {
                    g.setColor(DARK_RED);
                } else {
                    g.setColor(DARK_GREEN);
                }
            }
            g.fillRect(x, y-6,20, 2);
            g.fillRect(x, y+6,20, 2);
            g.fillRect(x, y-6, 2,12);
        }

        private void drawQueue(int x, int y, Graphics g, int id) {
            g.fillRect(Xpos, y-10,x, 2);
            g.fillRect(Xpos, y+10,x, 2);
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
            
            for(int i=0;i<N_QUEUES;i++) this.drawQueue(X_QUEUE,queuePosition(i),g,i);

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

    class SpazioMonitor {
        private int X, Y;         // dimensioni dell'ufficio
        
        private boolean[][] persona;  // mutex per le persone che si muovono nell'ufficio

        public SpazioMonitor(int x, int y) {
            this.X = x;
            this.Y = y;

            // inizialmente non ci sono persone (false)
            persona  = new boolean[X][Y];    
        }

        // si muove da x,y a nx,ny. Se nx,ny è occupato attende altrimenti
        // occupa nx,ny e libera x,y.
        public synchronized void move(int x, int y, int nx, int ny) 
                throws InterruptedException {
            while (persona[nx][ny])
                wait();             // attende se c'è una persona in nx,ny
            
            // acquisisce la nuova posizione nell'ufficio postale
            persona[nx][ny] = true; 

            // libera la posizione vecchia
            libera(x,y);            
        }

        // libera la posizione x,y (invocata quando l'utente esce dall'ufficio)
        public synchronized void libera(int x, int y) {
            // rilascia la posizione vecchia
            persona[x][y]   = false; 

            // notifica eventuali thread in attesa della posizione x,y
            notifyAll();                
        }
    }

    class Person extends Thread {
        int id;
        int x=-1;
        int y=-1;
        int newx, newy;
        int counter;
        int speed;
        boolean priority;

        public Color color;
        public boolean accident = false;
        public boolean queueviolation = false;
        public boolean priorityviolation = false;

        Random rand = new Random();

        Person(int id) {
            this.id = id;
            priority = rand.nextBoolean() && rand.nextBoolean();
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

                synchronized(s) {
                    s.move(x/Xpos,y/Ypos,newx/Xpos,newy/Ypos);
                    if (checkAccident()) return false; // should be prevented by move
                    x = newx; y = newy;
                }
                pausePerson();            
            }
            return true;
        }

        private void go() throws InterruptedException {
            //System.out.println("Hey Person "+id);
            sleep((long)(SLEEP_PERSON*id*SLEEP_GAP));

            int counter=0; // not used, just one counter
            int queue = (priority) ? 0 : 1;
            speed = rand.nextInt(SLEEPSPEED);

            color = colors[queue];

            x = 0;
            y = queuePosition(queue);

            if (!moveto(X_QUEUE,y))
                return; // exits if someone else crashed into me

            synchronized(p) {
                if (priority) {
                    priority_waiting=true;
                }

                p.attendiSportello(priority); // waits for a free counter

                if (!priority && priority_waiting) {
                    System.out.println("Coda prioritaria non rispettata!");
                    color = Color.RED;
                    priorityviolation = true;
                }
                if (priority) {
                    priority_waiting=false;
                }
                if (occupied[counter] > 0) {
                    System.out.println("Sportello già occupato!");
                    color = Color.RED;
                    queueviolation = true;
                    // return;
                }
                occupied[counter] += 1;
            }

            if (!moveto(X_COUNTER-Xpos,counterPosition(counter)))
                return; // exits if someone else crashed into me


            sleep(SLEEP_SERVICE);
            synchronized(p) {
                occupied[counter] -= 1;
            }
            p.liberaSportello();


            if (!moveto(x,y-Ypos))
                return; // exits if someone else crashed into me

            if (!moveto(X,y))
                return; // exits if someone else crashed into me
          
            s.libera(x/Xpos,y/Ypos);
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


