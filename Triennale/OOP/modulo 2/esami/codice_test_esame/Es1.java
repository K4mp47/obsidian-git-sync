
// Questo sorgente contiene le soluzioni dell'esame scritto di PO2 del 1/7/2022 per ciò che riguarda i quesiti 1-2, ovvero le domande che coinvolgono Java.
// Il quesito 3 riguardante C++ è in un progetto Visual Studio a parte, non qui.
// Il codice qui esposto è Java 8+.

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.function.Function;

import Es7.Random;

public class Es1 {

    // 1.a
    public interface Predicate<T> extends Function<T, Boolean> {}

    // 1.b
    public interface Either<T> {
        T onSuccess(T x);
        void onFailure(T x) throws Exception;
    }

    // 1.c
    public static class SkippableArrayList<E> extends ArrayList<E> {
        public Iterator<E> iterator(Predicate<E> p, Either<E> f) {
            final Iterator<E> it = super.iterator();    // può anche essere un campo privato della anonymous class
            return new Iterator<E>() {
                @Override
                public boolean hasNext() {
                    return it.hasNext();
                }

                @Override
                public E next() {
                    E x = it.next();
                    if (p.apply(x))
                        return f.onSuccess(x);
                    else {
                        try {
                            f.onFailure(x);
                        }
                        catch (Exception e) {
                            e.printStackTrace();    // si può anche non fare niente dentro il catch, è indifferente
                        }
                        return x;
                    }
                }
            };
        }
    }

    public static void main(String[] args) {
        Collection<Integer> dst = new ArrayList<>();
        SkippableArrayList<Integer> src = new SkippableArrayList();

        Random r = new Random();

        Iterator<Integer> it = src.iterator((x) -> x > 5, new Either<Integer>() {
            @Override
            public Integer onSuccess(Integer x) {
                return x + 1;
            }

            @Override
            public void onFailure(Integer x) throws Exception {
                dst.add(x);
            }
        }
        );

        for(int i = 0; i < 10; i++)
            src.add(r.nextInt(10));

        while (it.hasNext())
            System.out.println(it.next());
    }

}