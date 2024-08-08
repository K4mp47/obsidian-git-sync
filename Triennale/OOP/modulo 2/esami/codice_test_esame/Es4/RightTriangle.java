package Es4;

public class RightTriangle extends Triangle {
    
    public RightTriangle(Point a, Point b, Point c){
        super(a,b,c);
        assert isRectangular();
    }

    private boolean isRectangular(){
        Point a = points.get(0);
        Point b = points.get(1);
        Point c = points.get(2);

        double lab = Math.pow(a.x- b.x, 2) + Math.pow(a.y - b.y,2);
        double lac = Math.pow(a.x- c.x, 2) + Math.pow(a.y - c.y,2);
        double lbc = Math.pow(b.x- c.x, 2) + Math.pow(b.y - c.y,2);
        return (lab + lac == lbc) || (lab + lbc == lac) || (lbc + lac == lab);
    }

    @Override
    public double area(){
        Point a = points.get(0);
        Point b = points.get(1);
        Point c = points.get(2);

        double lab = Math.pow(a.x- b.x, 2) + Math.pow(a.y - b.y,2);
        double lac = Math.pow(a.x- c.x, 2) + Math.pow(a.y - c.y,2);
        double lbc = Math.pow(b.x- c.x, 2) + Math.pow(b.y - c.y,2);

        double lines[] = {lab,lac,lbc};

        java.util.Arrays.sort(lines);

        return (lines[0] * lines[1]) / 2;
    }
}
