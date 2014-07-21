import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.Queue;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.concurrent.PriorityBlockingQueue;

public class Main {

    private static String PATH_STRECKEN_1_000 = "resources/Strecken_1000.txt";

    private static String PATH_STRECKEN_10_000 = "resources/Strecken_10000.txt";

    private static String PATH_STRECKEN_100_000 = "resources/Strecken_100000.txt";

    public static void main(String[] args) throws IOException {
        for (String path : Arrays.asList(PATH_STRECKEN_1_000, PATH_STRECKEN_10_000, PATH_STRECKEN_100_000)) {
            System.out.println("Starting lineSweep for " + path);
            System.out.println("# of intersections: " + numIntersectionsForFile(path));
        }
    }

    private static int numIntersectionsForFile(String path) throws IOException {
        List<Segment> segments = readLines(path);
        Queue<Event> eventQueue = initEventQueue(segments);
        SweepLine sweepLine = new SweepLine();
        sweepLine.process(eventQueue);
        return sweepLine.getNumIntersections();
    }

    private static List<Segment> readLines(String path) throws IOException {
        List<Segment> lines = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(new File(path)))) {
            String line;
            while ((line = reader.readLine()) != null) {
                lines.add(byLine(line));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return lines;
    }

    private static Segment byLine(String line) {
        String[] pointsAsStrings = line.split(" ");
        return new Segment(
            Double.parseDouble(pointsAsStrings[0])
            , Double.parseDouble(pointsAsStrings[1])
            , Double.parseDouble(pointsAsStrings[2])
            , Double.parseDouble(pointsAsStrings[3]));
    }

    private static Queue<Event> initEventQueue(Collection<Segment> segments) {
        Queue<Event> eventQueue = new PriorityBlockingQueue<>();
        segments.forEach((segment) -> {
            eventQueue.add(new SegmentStart(segment));
            eventQueue.add(new SegmentEnd(segment));
        });
        return eventQueue;
    }
}
