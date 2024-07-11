package esame2;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.function.Function;

public class FactorialThread extends Thread {

    private Integer n;

    public FactorialThread(Integer n) {
        this.n = n;
    }

    @Override
    public void run() {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        n = result;
    }

    public Integer getFactorial() throws InterruptedException {
        this.join();
        return n;
    }
}

class Main {

    public static <T> Collection<FactorialThread> parallelFactorial(Collection<T> numbers) {
        return map(numbers, n -> {
            FactorialThread jo = new FactorialThread((Integer) n);
            jo.start();
            return jo; 
        });
    }

    static <A, B> List<B> map(Iterable<A> i, Function<A, B> f) {
        List<B> l = new ArrayList<>();
        for (A a : i) {
            l.add(f.apply(a));
        }
        return l;
    }

    public static void main(String[] args) throws InterruptedException {
        FactorialThread f = new FactorialThread(5);
        f.start();
        System.out.println(f.getFactorial());
        Collection<FactorialThread> threads = parallelFactorial(new ArrayList<>(List.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)));
        for (FactorialThread t : threads) {
            System.out.println(t.getFactorial());
        }
    }
}
