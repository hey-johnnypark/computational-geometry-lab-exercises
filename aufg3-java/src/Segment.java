import java.awt.geom.Line2D;
import java.awt.geom.Point2D;

public class Segment extends Line2D.Double implements Comparable<Segment> {

    public Segment(double x1, double y1, double x2, double y2) {
        super(x1, y1, x2, y2);
    }

    @Override
    public int compareTo(Segment o) {
        Point2D leftThis = findLeftPoint();
        Point2D leftOther = findLeftPoint(o);
        if (leftThis.getY() < leftOther.getY()) {
            return -1;
        } else if (leftThis.getY() > leftOther.getY()) {
            return 1;
        } else {
            return 0;
        }
    }

    private Point2D findLeftPoint(Segment segment) {
        return segment.getX1() < segment.getY1() ? segment.getP1() : segment.getP2();
    }

    private Point2D findLeftPoint() {
        return findLeftPoint(this);
    }

    @Override
    public String toString() {
        return String.format("%s[%s -> %s]", getClass().getSimpleName(), getP1().toString(), getP2()
            .toString());
    }

}
