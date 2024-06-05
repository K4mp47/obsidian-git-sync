import java.util.Collection;
import java.util.Iterator;

public class Es8 {
    /*
    * public interface Comparable<T>{
    *       int compareTo(T o)
    *
    * }
    *
    *
    * */

   /* public class Car implements Comparable<Car>{
        int speed;

        @Override
        public int compareTo(Car o) { // this  -  o
            return this.speed-o.speed;
        }*/

        /*risultato comparison a tre vie:
        * 0    -> se gli elementi sono uguali
        * >0   -> se a > b
        * <0   -> se a < b */
    /*}


    public class Bike {
        int dim;

    }
    public class Car2 implements Comparable<Bike>{
        int dim;
        @Override
        public int compareTo(Bike o) {
            return this.dim - o.dim;
        }
        // this-> Car2
        // param compareTo -> Bike
    }*/


    // B
    // A implements Comparable<B>

    public static <A extends Comparable<B>, B> int compareMany(Collection<A> a, Collection<B> b){
        Iterator<A> ia = a.iterator();
        Iterator<B> ib = b.iterator();

        int r = 0;

        while(ia.hasNext() && ib.hasNext()){
            A x = ia.next();
            B y = ib.next();
            r = x.compareTo(y);
            if(r!=0) return r;
        }
        // r = 0 -> comparison tra elementi

        return ia.hasNext() && !ib.hasNext() ? 1 : !ia.hasNext() && ib.hasNext() ? -1 : 0;


        /* operatore ternario:
        se a è vero ritorno b, altrimenti ritorno c
        a ? b : c*/

    }


}
