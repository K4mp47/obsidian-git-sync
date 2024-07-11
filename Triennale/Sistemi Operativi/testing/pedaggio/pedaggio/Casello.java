import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.JPanel;

import java.util.Random;

final public class Casello
{

    JFrame frame;
    DrawPanel drawPanel;

    // Dimension of the panel
    private final int X = 500;
    private final int Y = 300;

    // position of tolls
    private final int X_TOLL = 400;

    // dimension of the position square
    private final int Xpos = 20;
    private final int Ypos = 20;

    private final int N_CARS = 100;  // Number of car threads
    private final int N_TOLLS = 6;  // Number of tollbooths

    private final int SLEEPCAR = 500;
    private final int SLEEPTOLL = 3000;
    private final int SLEEPSPEED = 100;

    private final int FEE = 100;

    private int nPaid = 0; // number of paid tolls
    private int nPassed = 0; // number of passed cars

    private Car[] car = new Car[N_CARS]; // Array for car threads

    private Pedaggio p = new Pedaggio(X/Xpos+1,Y/Ypos+1,N_TOLLS); // Monitor

    private int oneX = 7;
    private int oneY = 7;

    boolean up = false;
    boolean down = true;
    boolean left = false;
    boolean right = true;

    Casello() {

    }

    public static void main(String... args) throws InterruptedException
    {
        new Casello().go();
    }

    private int tollPosition(int id) {
        return  Y/(N_TOLLS+1)*(id+1)/Ypos*Ypos;
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

        // Starts tolls and car threads
        for (int i=0; i<N_TOLLS; i++) {
            new Toll(i).start();
        }
        for (int i=0; i<N_CARS; i++) {
            car[i] = new Car(i);
            car[i].start();
        }
        new Show().start();

        for (int i=0; i<N_CARS; i++) {
            car[i].join();
            //System.out.println("Terminata "+i);
        }
        System.out.println("Le auto sono transitate ...");

        boolean failure = false;
        for(int i=0;i<N_CARS;i++) {
            if (car[i].accident) {
                System.out.println(">>> Auto "+i+" incidentata!");
                failure = true;
            }
        }
        if (nPaid < nPassed) {
            System.out.println("Passate "+nPassed+" auto con solo "+nPaid+" pedaggi!");
            failure = true;
        }
        else if (nPaid > nPassed + N_TOLLS) {
            System.out.println("Passate solamente "+nPassed+" con "+nPaid+" pedaggi!");
            failure = true;
        }
        if (!failure) {
            System.out.println("Nessuna auto incidentata e pedaggi OK!");
            System.exit(0);
        } else {
            System.exit(1);
        }
        //moveIt();

    }

    class DrawPanel extends JPanel
    {
        private static final long serialVersionUID = 1L;

        private void drawCar(int x, int y, boolean accident, Graphics g) {
            // g.setColor(Color.BLUE);
            // g.fillRect(x, y, 100, 30);
            // g.setColor(Color.BLACK); // body
            // g.fillOval(x + 15, y + 20, 15, 15); // wheel
            // g.fillOval(x + 60, y + 20, 15, 15); // wheel
            // g.fillRect(x + 15, y - 20, 60, 20); // top
            if(x >=0 && y >=0) {
                if (accident)
                    g.setColor(Color.RED);
                else
                    g.setColor(Color.BLUE);

                g.fillOval(x, y-5, 20, 10);
            }
        }

        private void drawToll(int x, int y, Graphics g) {
            g.setColor(Color.BLACK);
            g.fillRect(x, y-6,20, 2);
            g.fillRect(x, y+6,20, 2);
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
            // g.fillRect(oneX, oneY, 6, 6);
            
            for(int i=0;i<N_TOLLS;i++) this.drawToll(X_TOLL,tollPosition(i),g);
            // System.out.println(" " + this.getWidth() + " " + this.getHeight());
            for(int i=0;i<N_CARS;i++) {
                try {
                    this.drawCar(car[i].getX(),car[i].getY(),car[i].accident,g);
                } catch (NullPointerException e) {
                }
            }
        }
    }

    class Car extends Thread {
        int id;
        int x=-1;
        int y=-1;
        int newx, newy;
        int toll;
        int speed;
        public boolean accident = false;

        Random rand = new Random();

        Car(int id) {
            this.id = id;
        }

        private boolean checkAccident() {
            for(int i=0;i<N_CARS;i++) {
                if (i == id) continue;
                try {
                    if (car[i].getX() == newx && car[i].getY() == newy) {
                        System.out.println("Incidente!");
                        accident=true;
                        car[i].accident=true;
                        return true;
                    }
                } catch (NullPointerException e) {
                }
            }
            return false;
        }

        private void pauseCar() {
            try {
                sleep(SLEEPCAR-speed);
            } catch (InterruptedException e) {
                System.out.println("Interrupted car "+id);
            }
        }

        public void run() {
            try {
                go();
            } catch (InterruptedException e) {
                System.out.println("Auto "+id+ " interrotta!");
            }
        }
        private void go() throws InterruptedException {
            //System.out.println("Hey Car "+id);
            sleep(SLEEPCAR*id);

            x = 0;
            y = rand.nextInt(Y/Ypos)*Ypos;
            int toll = rand.nextInt(N_TOLLS);
            speed = rand.nextInt(SLEEPSPEED);

            while( x < X_TOLL) {
                if (accident) return; // exits if someone else crashed into me
                
                // move
                newx+=Xpos;
                if (y < tollPosition(toll))
                    newy = y + Ypos;
                else if (y > tollPosition(toll))
                    newy = y - Ypos;

                synchronized(p) {
                    p.move(x/Xpos,y/Ypos,newx/Xpos,newy/Ypos);
                    if (checkAccident()) return; // should be prevented by move
                    x = newx; y = newy;
                }

                pauseCar();            
            }

            // paga
            int pagato = 0, myp;
            while (pagato < FEE) {
                myp = rand.nextInt(FEE-pagato+1);
                
                p.paga(toll,myp);

                pagato += myp;
            }
            p.attendiOK(toll);
            synchronized(p) {
                nPassed++;
            }

            while( x < X) {
                if (accident) return; // exits if someone else crashed into me

                // move
                newx =x+Xpos;


                synchronized(p) {
                    p.move(x/Xpos,y/Ypos,newx/Xpos,y/Ypos);
                    if (checkAccident()) return; // should be prevented by move
                    x = newx;
                }

                pauseCar();            
           
            }
            p.libera(x/Xpos,y/Ypos);
            x = -1;
            //System.out.println("Done Car "+id + " "+y+" "+toll);

        }
        public int getX() { return x; }
        public int getY() { return y; }
    }

    class Toll extends Thread {
        int id;
        Toll(int id) {
            this.id = id;
        }    
        public void run() {
            try {
                go();
            } catch (InterruptedException e) {
                System.out.println("Auto "+id+ " interrotta!");
            }
        }

        private void go() throws InterruptedException {
            //System.out.println("Hey Toll "+id);
            while(true) {
                p.incassa(id,FEE);
                synchronized(p) {
                    nPaid++;
                }
                if (nPaid < nPassed)
                    System.out.println("Passate "+nPassed+" auto con solo "+nPaid+" pedaggi!");
                else if (nPaid > nPassed + N_TOLLS)
                    System.out.println("Passate solamente "+nPassed+" con "+nPaid+" pedaggi!");
                try {
                    sleep(SLEEPTOLL);
                } catch (InterruptedException e) {
                    System.out.println("Interrupted toll "+id);
                }
            }
        }
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


