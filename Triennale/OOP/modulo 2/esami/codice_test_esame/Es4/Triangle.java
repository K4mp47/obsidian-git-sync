package Es4;

import java.util.List;

public class Triangle extends Polygon {

    public Triangle(Point a, Point b, Point c) {
        super(List.of(a, b, c));
    }

    @Override
    public double area() {
        Point a = points.get(0);
        Point b = points.get(1);
        Point c = points.get(2);

        return 0.5 * Math.abs(
                a.x * (b.y - c.y)
                + b.x * (c.y - a.y)
                + c.x * (a.y - b.y)
        );
    }
}
