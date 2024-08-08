package Es2;
import java.util.Iterator;

public class Es2 {
    public static <A, B, C> Iterator<Triple<A, B, C>> evalIterator(Iterator<Pair<A, B>> p, BiFunction<A, B, C> f) {
        return new Iterator<>() {
            
            @Override
            public boolean hasNext(){
                return p.hasNext();
            }

            @Override
            public Triple<A, B, C> next(){
                Pair<A,B> tmp = p.next();
                
                return new Triple<>(tmp.a, tmp.b, f.apply(tmp.a, tmp.b));
            }
        };
    }
}   
