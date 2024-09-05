package esami2.esame4;

public class Edge implements Comparable<Edge> {

    private final double len;

    public Edge(double len) {
        this.len = len;
    }

    public double length() {
        return len;
    }

    @Override
    public int compareTo(Edge s) {
        return Library.compareBy(this, s, (x) -> x.length());
    }
}
