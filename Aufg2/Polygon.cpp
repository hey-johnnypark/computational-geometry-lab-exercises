#include "Polygon.h"
#include "LineSegment.h"

Polygon::Polygon(std::vector<Point> points) {
	this->points = points;
}

Polygon::~Polygon() {

}

bool Polygon::pointInPolygon(Point point){
	std::vector<Point> points = this->points;
	points.size();
	float minX = 0;
	Point qA = Point(0,0);
	for(unsigned int i = 0; i < points.size(); i++){
		if(points.at(i).getX() < minX){
			minX = points.at(i).getX();
			qA.setX(points.at(i).getX() -1 );
			qA.setY(points.at(i).getY());
		}
	};


	int i = 1;
	while(ccw(qA, point, points.at(i)) == 0){
		i += 1;
	}
	int g = 0;
	int s = 0;
	int lr = sgn(ccw(qA, point, points.at(i)));
	for(unsigned int j = i + 1; j < points.size(); j++){
		int lrnew = sgn(ccw(qA, point, points.at(j)));
		if(abs(lrnew - lr) == 2){
			lr = lrnew;
			if((ccw(points.at(j-1), points.at(j), qA) * ccw(points.at(j-1), points.at(j), point)) <= 0){
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
