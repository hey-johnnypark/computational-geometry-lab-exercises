import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.geom.Line2D;
import java.util.ArrayList;

import javax.swing.JComponent;

class LineComponent extends JComponent {

    ArrayList<Line2D.Double> lines;

    LineComponent() {
        super();
        setPreferredSize(new Dimension(200, 200));
        lines = new ArrayList<Line2D.Double>();
    }

    public void addLine(Line2D.Double line) {
        lines.add(line);
        repaint();
    }

    public void paintComponent(Graphics g) {
        g.setColor(Color.white);
        g.fillRect(0, 0, getWidth(), getHeight());
        Dimension d = getPreferredSize();
        g.setColor(Color.black);
        for (Line2D.Double line : lines) {
            g.drawLine(
                (int) line.getX1(),
                (int) line.getY1(),
                (int) line.getX2(),
                (int) line.getY2()
                );
        }
    }
}
