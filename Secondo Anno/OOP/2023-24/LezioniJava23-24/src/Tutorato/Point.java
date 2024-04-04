package Tutorato;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.function.Function;

interface Solid extends Comparable<Solid> {
    double area();

    double volume();

    PositionedSolid at(Point origin);

    static <S extends Solid> int compareBy(Function<S, Double> f, S s1, S s2) {
        return Double.compare(f.apply(s1), f.apply(s2));
    }

    static <S extends Solid> Comparator<S> comparatorBy(Function<S, Double> f) {
        return (s1, s2) -> compareBy(f, s1, s2);
    }

    default int compareTo(Solid s) {
        return compareBy((x) -> x.volume(), this, s);
    }
}

interface Polyhedron extends Solid {
    double perimeter();

    @Override
    PositionedPolyhedron at(Point origin);
}

interface PositionedSolid {
    Point origin();
}

interface PositionedPolyhedron extends PositionedSolid, Iterable<Point> {

}

class Sphere implements Solid {
    private double ray;

    public Sphere(double ray) {
        this.ray = ray;
    }

    @Override
    public double area() {
        return 4 * Math.PI * ray * ray;
    }


    @Override
    public double volume() {
        return 4 / 3 * Math.PI * ray * ray * ray;
    }

    @Override
    public PositionedSolid at(Point origin) {
        return () -> origin;
    }
}

class Cube implements Polyhedron {
    private double side;

    public Cube(double side) {
        this.side = side;
    }
    @Override
    public double area() {
        return 6 * side * side;
    }

    @Override
    public double volume() {
        return side * side * side;
    }

    @Override
    public double perimeter() {
        return 12 * side;
    }


    /*
    * QUESTION: La classe come segue, può essere implementata tramite lambda?
    *
    * se ci fosse solo origin, allora () -> origin
    *
    * ma ci sono due metodi, non è possibile usare la lambda
    *
    * */
    @Override
    public PositionedPolyhedron at(Point origin) {
        return new PositionedPolyhedron() {
            @Override
            public Point origin() {
                return origin;
            }

            // Implementazione dell'iteratore
            @Override
            public Iterator<Point> iterator() {
                final Point u = origin.move(side, side, side);
                final Point[] ps = new Point[] {origin, origin.move(side, 0, 0), origin.move(0, side, 0), origin.move(0, 0, side), u, u.move(side, 0, 0), u.move(0, side, 0), u.move(0, 0, side)};

                return Arrays.asList(ps).iterator();
            }
        };
    }

    // non posso istanziare l'interfaccia, devo per forza usare un anonymous class
}

public class Point {
    public final double x;
    public final double y;
    public final double z;

    public Point(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public Point move(double dx, double dy, double dz) {
        return new Point(x + dx, y + dy, z + dz);
    }

}