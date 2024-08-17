package esami.esame4;

public interface Polygon extends Surface, Iterable<Edge> {

    @Override
    default double perimiter() {
        return Library.sumBy(this, (x) -> x.length());  
    }
}
