import java.awt.geom.Line2D;

public class SegmentStart extends Event {

    public SegmentStart(Segment segment) {
        super(Type.SEGMENT_START);
        setX(getStart(segment));
        setSegment(segment);
    }

    private double getStart(Line2D segment) {
        return segment.getX1() < segment.getX2() ? segment.getX1() : segment.getX2();
    }

}
