package esami2.esame4;

public interface Solid extends Comparable<Solid> {

    double outerArea(); // area laterale totale 

    double volume();

    @Override
    default int compareTo(Solid s) {
        return Library.compareBy(this, s, (x) -> x.volume());   
    }
}
