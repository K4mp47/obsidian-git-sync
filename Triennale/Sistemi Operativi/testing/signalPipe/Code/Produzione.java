import java.util.concurrent.Semaphore;

public class Produzione {

    // crea dei semafori per sincronizzare i thread
    int max = 20;
    final private Semaphore pieno = new Semaphore(0);
    final private Semaphore vuoto = new Semaphore(max);
    private final Semaphore mutex = new Semaphore(1);
    final private Integer buffer[] = new Integer[max];
    private int indexP = 0;
    private int indexL = 0;
    private int num = 0;

    public class Produttore extends Thread {
        @Override
        public synchronized void run() {
            while (num < 1000) {
                try {
                    vuoto.acquire(); // aspetto una cella vuota
                    vuoto.acquire(); // aspetto una cella vuota
                    mutex.acquire(); // blocco di scrittura nel buffer
                    buffer[indexP%max] = num;
                    System.out.println("ho scritto:" +buffer[indexP%max]);

                    num++;
                    indexP++;
                    buffer[indexP%max] = num;
                    System.out.println("ho scritto:" +buffer[indexP%max]);
                    num++;
                    indexP++;
                    mutex.release(); // rimuovo blocco
                    pieno.release(); // un blocco è stato scritto
                    pieno.release(); // un blocco è stato scritto
                } catch (InterruptedException e) {
                    e.printStackTrace(System.out);
                }
            }
        }
    }

    public class Consumatore extends Thread {
        @Override
        public synchronized void run() {
            while (true) {
                try {
                   pieno.acquire();
                   mutex.acquire();
                   System.out.println(buffer[indexL%max]);
                   indexL++;
                   mutex.release();
                   vuoto.release();
                } catch (InterruptedException e) {
                    e.printStackTrace(System.out);
                }
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Produzione produzione = new Produzione();
        Produzione.Produttore p = produzione.new Produttore();
        Consumatore c = produzione.new Consumatore();

        p.start();
        c.start();

        p.join();
        c.join();
    }
}
