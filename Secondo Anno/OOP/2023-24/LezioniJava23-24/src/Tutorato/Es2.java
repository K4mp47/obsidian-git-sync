package Tutorato;

import java.util.Iterator;
import java.util.List;

public class Es2 {

    public abstract class Polygon {
        public double perimeter() {
            Iterator<Line> lineIterator = lineIterator();
            double r = 0;
            while (lineIterator.hasNext()) {
                Line l = lineIterator.next();
                r += l.length();
            }
            return r;
        }

        protected final List<Point> points;
        public abstract double area();
        protected Polygon(List<Point> points) {
            assert points.size() >= 3; // runtime check
            this.points = points;
        }

        public Iterator<Line> lineIterator() {
            return new Iterator<Line>() {
                private final Iterator<Point> it = points.iterator();

                private Point last = it.next();

                @Override
                public boolean hasNext() {
                    return it.hasNext();
                }

                // salvo il successivo, creo il nuovo oggetto che torno
                // alla prossima chiamata punto ad una nuova linea
                @Override
                public Line next() {
                    Point next = it.next();
                    Line r = new Line(last, next);
                    last = next;
                    return r;
                }
            };
        }

    }
    public class Point {
        public final double x;
        public final double y;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    public class Line {
        private final Point p1;
        private final Point p2;

        public Line(Point p1, Point p2) {
            this.p1 = p1;
            this.p2 = p2;
        }

        public double length() {
            return Math.sqrt(Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2));
        }
    }
}
