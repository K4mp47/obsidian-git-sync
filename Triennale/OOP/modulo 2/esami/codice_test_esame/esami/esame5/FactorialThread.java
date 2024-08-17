package esami.esame5;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.function.Function;

public class FactorialThread extends Thread {

    private final int number;
    private int factorial = 1;

    @Override
    public void run() {
        // Implementazione del metodo run
        for (int i = 1; i <= number; i++) {
            factorial *= i;
        }
    }

    public FactorialThread(Integer number) {
        // Implementazione del costruttore
        this.number = number;
    }

    public Integer get() {
        return factorial;
    }

    static <A, B> List<B> map(Iterable<A> i, Function<A, B> f) {
        List<B> result = new ArrayList<>();
        for (A x : i) {
            result.add(f.apply(x));
        }

        return result;
    }

    static List<FactorialThread> parallelFactorial(Iterable<Integer> c) {

        List<FactorialThread> threads = new ArrayList<>();

        for (Integer x : c) {
            FactorialThread t = new FactorialThread(x);
            threads.add(t);
            t.start();
        }

        return threads;
    }

    static Collection<FactorialThread> parallelFactorialTwo(Iterable<Integer> c) {
        return map(c, (x) -> {
            FactorialThread t = new FactorialThread(x);
            t.start();
            return t;   
        });
    }

    public static void main(String[] args) {
        // Implementazione del metodo main
        Collection<Integer> c = List.of(1, 2, 3, 4, 5);
        Collection<FactorialThread> threads = parallelFactorial(c);
        for (FactorialThread thread : threads) {
            System.out.println(thread.get());
        }

        Collection<FactorialThread> result = parallelFactorialTwo(List.of(1, 2, 3, 4, 5));
        System.out.println(result);
        System.out.println("Threads terminated");
    }
}
