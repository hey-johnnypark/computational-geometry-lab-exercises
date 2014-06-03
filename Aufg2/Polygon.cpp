#include "Polygon.h"

Polygon::Polygon(std::vector<Point> points) {
	this->points = points;
}

Polygon::~Polygon() {

}

bool Polygon::pointInPolygon(Point point){
	std::vector<Point> points = this->points;
	points.size();
	Point qA = Point(-1,-1);
	int i = 1;
	while(ccw(qA, point, points.at(i)) == 0){
		i += 1;
	}
	int s = 0;
	int lr = sgn(ccw(qA, point, points.at(i)));
	for(unsigned int j = i + 1; j < points.size(); j++){
		int lrnew = sgn(ccw(qA, point, points.at(j)));
		if(lrnew - lr == 2){
			lr = lrnew;
			if(ccw(points.at(j-1), points.at(j), qA) * ccw(points.at(j-1), points.at(j), point)){
				s = s + 1;
			}
		}
	}

	return s%2 != 0;
}

int Polygon::ccw(Point a, Point b, Point c) {
	return (a.getX() * b.getY() - a.getY() * b.getX())
				+ (b.getX() * c.getY() - b.getY() * c.getX())
				+ (a.getY() * c.getX() - a.getX() * c.getY());
}

int Polygon::sgn(int x)
{
  if (x > 0.0L)
    return 1.0L;
  else if (x < 0.0L)
    return -1.0L;
  else
    return 0.0L;
}
