package Es3;

public class FactThread extends Thread {

    public int n, res;

    public FactThread(int n) {
        this.n = n;
    }

    @Override
    public void run() {
        res = fact(n);
        int boh = fact(4);
        System.out.println(boh + " " + n);
    }

    public int fact(int n) {
        if (n <= 1) {
            return 1;
        }
        return n * fact(n - 1);
    }
}
