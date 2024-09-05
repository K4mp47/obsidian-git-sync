package esami2.esame2;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class FiboSequence implements Iterable<Integer>{
    
    private final int max;
    private final Map<Integer, Integer> cache = new HashMap<>();

    public FiboSequence(int max) {
        this.max = max;
    }

    @Override 
    public Iterator<Integer> iterator() {
        return new Iterator<Integer>() {
            private int n = 0;

            @Override
            public boolean hasNext() {
                return n < max;
            }

            @Override
            public Integer next() {
                return fib(n++);
            }

            private int fib(int n) {
                if(n < 2) return 1;
                else {
                    Integer cached = cache.get(n);
                    if(cached != null) return cached;
                    else {
                        int result = fib(n - 1) + fib(n - 2);
                        cache.put(n, result);
                        return result;
                    }
                }
            }
        };
    }

    public static void main(String[] args) {
        FiboSequence fs = new FiboSequence(10);
        for (int i : fs) {
            System.out.println(i);
        }
    }
}
