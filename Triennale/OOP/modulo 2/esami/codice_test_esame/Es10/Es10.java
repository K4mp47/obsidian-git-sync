package Es10;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Random;

public class Es10 {

    @FunctionalInterface
    public interface Function<T, R> {

        R apply(T a);
    }

    public static <A, B> Iterator<B> mapIterator(Iterator<A> it, Function<A, B> f) {
        return new Iterator<B>() {
            @Override
            public boolean hasNext() {
                return it.hasNext();
            }

            @Override
            public B next() {
                return f.apply(it.next());
            }
        };
    }

    public static class Pair<A, B> {

        public final A a;
        public final B b;

        public Pair(A a, B b) {
            this.a = a;
            this.b = b;
        }
    }

    public static <A> Iterator<Pair<A, A>> pairIterator(Iterator<A> it) {
        return new Iterator<>() {
            A last;

            @Override
            public boolean hasNext() {
                if (it.hasNext()) {
                    last = it.next();
                }
                return it.hasNext();
            }

            @Override
            public Pair<A, A> next() {
                return new Pair<>(last, it.next());
            }
        };
    }

    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            // generate random integers
            list.add(new Random().nextInt(100));
        }
		for (Integer i : list) {
			System.out.println(i);
		}

        Iterator<Pair<Integer, Integer>> it = pairIterator(list.iterator());
        Iterator<Double> ith = mapIterator(it, (Pair<Integer, Integer> p) -> Math.sqrt(p.a * p.a + p.b * p.b));

		System.out.println();
		while (ith.hasNext()) {
			System.out.println(ith.next());
		}
	}
}
