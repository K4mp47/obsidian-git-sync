package esami.esame4;

public interface Surface extends Comparable<Surface> {

    double area();

    double perimiter();

    @Override
    default int compareTo(Surface s) {
        return Library.compareBy(this, s, (x) -> x.area());
    }
}
