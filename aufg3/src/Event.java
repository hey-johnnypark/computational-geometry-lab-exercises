import java.awt.geom.Line2D;

public abstract class Event implements Comparable<Event> {

    public enum Type {
        SEGMENT_START, SEGMENT_END, SEGMENTS_INTERSECT
    }

    private Segment segment;

    private double x;

    private Type type;

    public Event(Type type) {
        this.type = type;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    @Override
    public int compareTo(Event other) {
        if (x < other.getX()) {
            return -1;
        } else if (x > other.getX()) {
            return 1;
        } else {
            return 0;
        }
    }

    public Type getType() {
        return type;
    }

    @Override
    public String toString() {
        return String.format("%s@x=%f", getClass().getSimpleName(), getX());
    }

    public Segment getSegment() {
        return segment;
    }

    public void setSegment(Segment segment) {
        this.segment = segment;
    }

}
