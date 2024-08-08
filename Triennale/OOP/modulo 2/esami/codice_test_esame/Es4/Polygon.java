package Es4;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public abstract class Polygon {

    protected final List<Point> points;

    protected Polygon(List<Point> points) {
        assert points.size() >= 3;
        this.points = points;
    }

    public Iterator<Line> lineIterator() {
        List<Line> lines = new ArrayList<>();
        for (Point p : points) {
            Point start = p;
            Point end = points.get(points.indexOf(p)+1 % points.size());
            Line line = new Line(start, end);
            lines.add(line);
        }
        return lines.iterator();
    }

    public double perimeter() {
        double per = 0;
        Iterator<Line> l = lineIterator();
        while(l.hasNext()){
            per += l.next().length();
        }
        return per;
    }

    public abstract double area();
}
