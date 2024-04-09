package MyThread;

public class Threads {

    public static void loop(String msg) {
        while(true) {
            System.out.println(msg);
        }
    }

    public static class MyThread extends Thread {
        @Override
        public void run() {
           while(true) {
               loop("ciao");
           }
        }
    }

    public static void main(String[] args) {
        Thread t = new MyThread();
        Thread t2 = new Thread(() -> loop("pluto"));
        t.start();
        try {
            t2.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        loop("pippo");
    }
}
