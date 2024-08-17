package esami.esame4;

public interface Polyhedron<P extends Polygon> extends Solid, Iterable<P> {

    @Override
    default double outerArea() {
        return Library.sumBy(this, (x) -> x.area());
    }
}
