package Es4;

public class Line {

    public final Point a, b;

    public Line(Point a, Point b) {
        this.a = new Point(a.x, a.y);
        this.b = new Point(b.x, b.y);
    }

    public double length() {
        return Math.sqrt(Math.pow((this.a.x - this.b.x), 2) + Math.pow((this.a.y - this.b.y), 2));
    }
}
