import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;
import java.util.function.Function;

interface Predicate<T> extends Function<T, Boolean> {
    // predicate diventa una funzione che torna un Boolean
}

interface Either<T> {
    T onSuccess(T obj);

    void onFailure(T obj) throws Exception;
}

public class SkippableArrayList<E> extends ArrayList<E>{

    Iterator<E> iterator(Predicate<E> p, Either<E> f) {
        return new Iterator<E>() {
            private int index = 0;

            @Override
            public boolean hasNext() {
                return index < size();
            }

            @Override
            public E next(){
                if (hasNext()) {
                    if (p.apply(get(index))) {
                        E x = f.onSuccess(get(index));
                        index++;
                        return x;
                    } else {
                        try {
                          f.onFailure(get(index));
                        } catch (Exception e) {
                            System.out.println(e.getMessage());
                        }  
                    } 
                    index++;
                }
                return get(index);
            }
        };
    }

    public static void main(String[] args) {
        SkippableArrayList<Integer> list = new SkippableArrayList<>();
        
        // generate a random number from 0 to 100
        int random = new Random().nextInt(100);
        list.add(random);
        random = new Random().nextInt(100);
        list.add(random);
        random = new Random().nextInt(100);
        list.add(random);
        random = new Random().nextInt(100);
        list.add(random);
        random = new Random().nextInt(100);
        list.add(random);

        for (Integer i : list) {
            System.out.println(i);
        }

        list.iterator(x -> x > 5, new Either<Integer>() {
            @Override
            public Integer onSuccess(Integer obj) {
                return obj+1;
            }
        
            @Override
            public void onFailure(Integer obj) throws Exception {
                throw new Exception("Odd number found");
            }
        });

        for (Integer i : list) {
            System.out.println(i);
        }
    }
}