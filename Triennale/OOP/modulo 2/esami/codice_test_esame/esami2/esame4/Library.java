package esami2.esame4;

import java.util.function.*;

public class Library {

    public static <T, State> State fold(Iterable<T> i, final State st0, BiFunction<State, T, State> f) {
        State st = st0;
        for (final T e : i) {
            st = f.apply(st, e);
        
        }return st;
    }

    public static <T> double sumBy(Iterable<T> it, Function<T, Double> f) {
        return fold(it, 0.0, (sum, element) -> sum + f.apply(element));
    }

    public static <T> int compareBy(T s1, T s2, Function<T, Double> f) {
        if((f.apply(s1) - f.apply(s2)) > 0 ) return 1;
        else if ((f.apply(s1) - f.apply(s2)) == 0) return 0;
        return -1;
    }
}
