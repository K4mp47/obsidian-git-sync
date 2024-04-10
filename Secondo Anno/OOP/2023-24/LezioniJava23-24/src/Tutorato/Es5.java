package Tutorato;
import java.util.Iterator;

public class Es5 {
    public interface Function<A, B> {
        B apply(A x);
    }

    public static <A, B> Iterator<B>  mapIterator(Iterator<A> it, Function<A, B> f) {
       // con un anonymous class posso istanziare subito
        return new Iterator<B>() {
            @Override
            public boolean hasNext() {
                return it.hasNext(); // wrappo la hasNext dentro it
            }
            @OverrideA
            public B next() {
                return f.apply(it.next());
            }
        }; // se non metto ; non è considerata un anonymous class
    }

    public static <A> Iterator<Pair<A, A>> pairIterator(Iterator<A> it) {
        return new Iterator<Pair<A, A>>() {
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

    public class Pair <A,B>{
        public A first; // se devo inserire che non possono essere modificati dovrebbero essere dichiarati final
        public B second;

        public Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }
}
