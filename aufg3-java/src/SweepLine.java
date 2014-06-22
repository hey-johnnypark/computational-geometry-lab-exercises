import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Queue;

public class SweepLine {

    private List<Segment> sweepLineSegments = new ArrayList<>();

    private int numIntersections = 0;

    private double currentEventX;

    public void process(Queue<Event> eventQueue) {
        Event event;
        while ((event = eventQueue.poll()) != null) {
            currentEventX = event.getX();
            switch (event.getType()) {
            case SEGMENT_START:
                Segment segment = event.getSegment();
                sweepLineSegments.add(segment);
                Collections.sort(sweepLineSegments);
                Collection<Segment> neighbours = findNeighbours(segment);
                for (Segment neighbourSegment : neighbours) {
                    if (segment.intersectsLine(neighbourSegment)) {
                        Point2D intersection = getIntersection(segment, neighbourSegment);
                        eventQueue.add(new SegmentsIntersect(segment, neighbourSegment, intersection.getX()));
                    }
                }
                break;
            case SEGMENT_END:
                sweepLineSegments.remove(event.getSegment());
            case SEGMENTS_INTERSECT:
                numIntersections++;
            default:
                break;
            }
        }
    }

    private Collection<Segment> findNeighbours(Segment segment) {
        Collection<Segment> neighbours = new ArrayList<>();
        int indexSegment = sweepLineSegments.indexOf(segment);
        try {
            neighbours.add(sweepLineSegments.get(indexSegment - 1));
        } catch (IndexOutOfBoundsException e) {
            // Skip
        }
        try {
            neighbours.add(sweepLineSegments.get(indexSegment + 1));
        } catch (IndexOutOfBoundsException e) {
            // skip
        }
        return neighbours;
    }

    public static Point2D getIntersection(final Segment line1, final Segment line2) {

        final double x1, y1, x2, y2, x3, y3, x4, y4;
        x1 = line1.x1;
        y1 = line1.y1;
        x2 = line1.x2;
        y2 = line1.y2;
        x3 = line2.x1;
        y3 = line2.y1;
        x4 = line2.x2;
        y4 = line2.y2;
        final double x = (
            (x2 - x1) * (x3 * y4 - x4 * y3) - (x4 - x3) * (x1 * y2 - x2 * y1)
            ) /
            (
            (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)
            );
        final double y = (
            (y3 - y4) * (x1 * y2 - x2 * y1) - (y1 - y2) * (x3 * y4 - x4 * y3)
            ) /
            (
            (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)
            );

        return new Point2D.Double(x, y);
    }

    public int getNumIntersections() {
        return numIntersections;
    }

    public double getCurrentEventX() {
        return currentEventX;
    }

}
