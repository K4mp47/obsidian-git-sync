package esami2.esame2;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

public class SkippableArrayList<E> extends ArrayList<E> {

    Iterator<E> iterator(Predicate<E> p, Either<E> f) {
        return new Iterator<E>() {
            private int index = 0;

            @Override
            public boolean hasNext() {
                return index < size();
            }

            @Override
            public E next() {
                if (hasNext()) {
                    E elem = get(index);
                    index++;
                    boolean t = p.apply(elem);
                    if (t == true) {
                        return f.onSuccess(elem);
                    } else try {
                        f.onFailure(elem);
                    } catch (Exception e) {
                        System.err.println(e.getMessage());
                        return elem;
                    }
                }
                return null;
            }
        };
    }

    public static void main(String[] args) {
        ArrayList<Integer> dst = new ArrayList<>();
        SkippableArrayList<Integer> src = new SkippableArrayList<>();

        for (int i = 0; i < 10; i++) {
            src.add(new Random().nextInt(11));
        }

        for (Object elem : src) {
            System.out.println(elem);
        }

        System.out.println();

        Iterator<Integer> it = src.iterator((x) -> x > 5, new Either<Integer>() {
            @Override
            public Integer onSuccess(Integer obj) {
                return obj + 1;
            }

            @Override
            public void onFailure(Integer obj) throws Exception {
                throw new Exception("Numero < 5");
            }
        });
        while (it.hasNext()) {
            dst.add(it.next());
        }

        System.out.println();

        for (Object elem : dst) {
            System.out.println(elem);
        }
    }
}
