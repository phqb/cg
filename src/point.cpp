#include "../include/point.h"

namespace cg {
	Point::Point() {}

	Point::Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	void Point::show() const {
		printf("(%.10lf, %.10lf)\n", this->x, this->y);
	}

	double Point::dist2(const Point & p) const {
		return (p.x - this->x)*(p.x - this->x) + (p.y - this->y)*(p.y - this->y);
	}

	Point Point::midPoint(const Point & p) const {
		return Point((this->x + p.x)/2, (this->y + p.y)/2);
	}
}