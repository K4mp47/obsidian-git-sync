package Es1;
import java.util.*;
import java.util.function.Function;

public class Es1 {

    public static class Point {

        private final double x, y, z;

        public Point(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public Point move(double dx, double dy, double dz) {
            return new Point(x + dx, y + dy, z + dz);
        }
    }

    public interface Solid extends Comparable<Solid> {

        double area();

        double volume();

        static <S extends Solid> int compareBy(Function<S, Double> f, S s1, S s2) {
            return Double.compare(f.apply(s1), f.apply(s2));
        }

        static <S extends Solid> Comparator<S> comparatorBy(Function<S, Double> f) {
            return (s1, s2) -> compareBy(f, s1, s2);
        }

        @Override
        default int compareTo(Solid o) {
            return compareBy((x) -> x.volume(), this, o);
        }
    }

    public interface PositionedSolid {

        Point origin();
    }

    public interface Polyhedron extends Solid {

        double perimeter();

        PositionedPolyhedron at(Point origin);
    }

    public interface PositionedPolyhedron extends PositionedSolid, Iterable<Point> {
    }

    public static class Cube implements Polyhedron {

        private final double side; // lato del cubo public 
        
        public Cube(double side) {
            this.side = side;
        }

        @Override
        public double area() {
            return side * side * 6;
        }

        @Override
        public double volume() {
            return side * side * side;
        }

        @Override
        public double perimeter() {
            return side * 12;
        }

        @Override
        public PositionedPolyhedron at(Point o) {
            // 1.d: questa anonymous class NON pu`o essere scritta come una lambda, 
            // perch´e ha 2 metodi 
            return new PositionedPolyhedron() {
                @Override
                public Point origin() {
                    return o;
                }
                
                @Override
                public Iterator<Point> iterator() {
                    final Point u = o.move(side, side, side);
                    final Point[] ps = new Point[]{
                        o, o.move(side, 0., 0.), o.move(0., side, 0.), o.move(0., 0., side), 
                        u, u.move(side, 0., 0.), u.move(0., side, 0.), u.move(0., 0., side),};
                    return Arrays.asList(ps).iterator();
                }
            };
        }
    }


    public class Sphere implements Solid {
    
        private final double ray;
    
        public Sphere(double ray){
            this.ray = ray;
        }
    
        @Override
        public double volume(){
            return (4.0/3.0)*3.14*Math.pow(ray, 3); 
        }

        @Override
        public double area(){
            return 4*3.14*Math.pow(ray,2);
        }

        // public PositionedPolyhedron at(Point o){
        //     return new PositionedPolyhedron() {

        //     }
        // }
    }

    public static void main(String[] args) {
        Comparator<Cube> cmp = Solid.comparatorBy(Solid::area);

        //create polyhedron list
        List<Cube> cubes = new ArrayList<>();
        Cube x = new Cube(12.);
        cubes.add(x);

        List<? extends Polyhedron> polys = cubes;
        for(Polyhedron pol: polys){
            System.out.println(pol.volume());
            System.out.println(pol.getClass());
            System.out.println(polys.getClass());
        }

        Point o = new Point(1., -1.5, 2.);
        for(Polyhedron pol: polys){
            for(Point t: pol.at(o)){
                System.out.println(t);
            }
        }
    }
}
