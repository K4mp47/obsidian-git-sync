package Es4;

import java.util.List;

public class Rectangle extends Polygon {

    public Rectangle(Point p1, Point p2) {
        /* 
         * The points in input must be the points of the diagonal
         */
        super(List.of(new Point(p1.x, p2.y), p2, new Point(p2.x, p1.y), p1));
    }

    @Override
    public double area(){
        Point a = points.get(0);
        Point b = points.get(1);
        Point c = points.get(2);

        double lines1 = Math.abs(a.x-b.x) + Math.abs(a.y-b.y);
        double lines2 = Math.abs(c.x-b.x) + Math.abs(c.y-b.y);
        return lines1 * lines2;
    }

    public static void main(String[] args) {
        Rectangle rec = new Rectangle(new Point(2,4), new Point(7,1));
        System.out.println(rec.area());
    }
}
