import java.awt.geom.Line2D;

public class SegmentsIntersect extends Event {

    private Segment intersectingSegment;

    public SegmentsIntersect(Segment segment, Segment intersectingSegment, double x) {
        super(Type.SEGMENTS_INTERSECT);
        setX(x);
        setSegment(segment);
        this.intersectingSegment = intersectingSegment;
    }

    public Line2D getIntersectingSegment() {
        return intersectingSegment;
    }

    public void setIntersectingSegment(Segment intersectingSegment) {
        this.intersectingSegment = intersectingSegment;
    }

}
