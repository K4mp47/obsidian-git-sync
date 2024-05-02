import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

class Scheduler {
  private int tempi[];
  private int CPU = 0;

  public Scheduler(int N_THREADS){
    tempi = new int[N_THREADS];
  }

  public int lessTime(){
    int[] tmp = tempi.clone();
    Arrays.sort(tmp);
    return tmp[0];
  }

  public void getCPU(int id, int time) throws InterruptedException{
    synchronized(this){
      System.out.println("Thread " + id + " richiede la CPU per " + time + " unità di tempo");
      while(lessTime() != tempi[id] || CPU == 1){
        wait();
      } 
      CPU = 1;
      tempi[id] += time;
    }
  } 

  public void releaseCPU(){
    synchronized(this){
      CPU = 0;
      notifyAll();
    }
  }
}

class Balancer{
    static JFrame frmMain;
    static Container pane;
    static JButton btnDo;
    static final int N_THREADS=5; // Numero di Thread che verranno eseguiti
    static JProgressBar[] bar = new JProgressBar[N_THREADS];
    static Scheduler s ; // Lo scheduler
    static JCheckBox testCheck;
 
    public static void main (String[] args){ //Main void
        int i,j;
 
        // Crea le componenti della GUI
        try {UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());}
        catch (Exception e) {}
        frmMain = new JFrame("Load balancer");
        frmMain.setSize(300, 80+25*N_THREADS); //Window size 300x100 pixels
        pane = frmMain.getContentPane();
        pane.setLayout(null); //Use the null layout
        frmMain.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //Exit when X is clicked
        btnDo = new JButton("Go!");
        for (i=0;i<N_THREADS;i++) {
            bar[i] = new JProgressBar(0, 100); //Min value: 0 Max value: 100
            bar[i].setBounds(10, 10+25*i, 280, 20);
            pane.add(bar[i]);
        }
        pane.add(btnDo);
        btnDo.setBounds(100, 10+25*N_THREADS, 100, 25);
        testCheck = new JCheckBox("Test");
        testCheck.setMnemonic(KeyEvent.VK_C);
        testCheck.setSelected(true);
        testCheck.setBounds(10, 10+25*N_THREADS, 100, 25);
        pane.add(testCheck);
        frmMain.setResizable(false);
        frmMain.setVisible(true);
        btnDo.addActionListener(new btnDoAction());
    }
 
    // Azione collegata alla pressione del pulsante
    public static class btnDoAction implements ActionListener{
        public void actionPerformed (ActionEvent e){
            MyThread[] t = new MyThread[N_THREADS];
            int i;
 
            // non parte se già attivi
            synchronized(this) {
                if (!btnDo.isEnabled())
                    return;
                btnDo.setEnabled(false);
            }
 
            s = new Scheduler(N_THREADS); // crea il monitor
            for (i=0;i<N_THREADS;i++) // azzera le progress bar
                bar[i].setValue(0);
 
            // crea e lancia i thread
            for (i=0;i<N_THREADS;i++) {
                t[i] = new MyThread(s,i);
                t[i].start();
            }
 
            // attende la terminazione
            new CloseThread(t).start();
        }
    }
 
    // Il codice dei thread
    public static class MyThread extends Thread{
        Scheduler s;    // lo scheduler (monitor) comune
        int id;         // l'id dei thread
        public MyThread(Scheduler s, int id) {
            this.s = s;
            this.id = id;
        }
        public void run(){
            int time;   // tempo di esecuzione
            int i, tmp[] = new int[N_THREADS]; // array per i test
 
            System.out.println("Thread " + id + " started!");
 
            while (bar[id].getValue() < 100) {
                time = (int)(5*Math.random());
                try {
 
                    /**** id chiede la CPU per un tempo time ****/
                    s.getCPU(id,time);
 
                } catch (InterruptedException e) {};
 
                for (i=0;i<N_THREADS;i++)
                    tmp[i] = bar[i].getValue();
 
                try {
                    sleep(time*50);
                } catch (InterruptedException e) {};
 
                if (testCheck.isSelected() ) {
                    for (i=0;i<N_THREADS;i++) {
                        if (tmp[i] != bar[i].getValue()) {
                            System.out.println("I Thread " + i + " e " +id + " si muovono assieme!");
                            System.exit(1);
                        }
                        if (bar[i].getValue() < bar[id].getValue()) {
                            System.out.println("Il Thread " + i + " era più indietro del thread " + id + "! Errore bilanciamento!");
                            System.exit(1);
                        }
                    }
                }
 
                bar[id].setValue(bar[id].getValue() + time);
                bar[id].repaint();
 
                /**** rilascia la CPU ****/
                s.releaseCPU();
            }
            System.out.println("Thread " + id + " terminated!");
 
        }
    }
 
    // thread che attende la terminazione
    public static class CloseThread extends Thread{
        MyThread[] t;
        public CloseThread (MyThread[] t) {
            this.t = t;
        }
 
        public void run() {
            int i;
 
            // attende la terminazione
            for (i=0;i<N_THREADS;i++) {
                try {
                    t[i].join();
                } catch (InterruptedException ei) {}
            }
 
            // attiva di nuovo il bottone
            btnDo.setEnabled(true);
 
        }
    }
}
