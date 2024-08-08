package Es4;

import java.util.Collection;
import java.util.Comparator;
import java.util.List;

public class Square extends Rectangle {

    public Square(Point p1, double side) {
        super(p1, new Point(p1.x + side, p1.y + side));
    }

    @Override
    public double area() {
        return super.area();
    }

    public static <T extends Polygon> T max(Collection<T> polygons, Comparator<? super T> comparator) {
        T max = null;
        for(T pol : polygons){
            if( max == null || comparator.compare(pol, max) > 0){
                max = pol;
            }
        }
        return max;
    }

    public static void main(String[] args) {
        Square rec = new Square(new Point(1, 1), 4);
        System.out.println(rec.area());
        Square sq1 = new Square(new Point(10., -4.), 0.1), sq2 = new Square(new Point(1., 20.), 0.01);
        Collection<Square> squares = List.of(sq1, sq2);
        Rectangle r = max(squares, new Comparator<Polygon>() {
            @Override
            public int compare(Polygon a, Polygon b) {
                return (int) (a.area() - b.area());
            }
        });
    }
}
