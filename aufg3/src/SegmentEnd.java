import java.awt.geom.Line2D;

public class SegmentEnd extends Event {

    public SegmentEnd(Segment segment) {
        super(Type.SEGMENT_END);
        setX(getEnd(segment));
        setSegment(segment);
    }

    private double getEnd(Line2D segment) {
        return segment.getX1() < segment.getX2() ? segment.getX2() : segment.getX1();
    }

}
