#include "../include/point_2.h"

namespace cg {
	Point_2::Point_2() {
		this->x = this->y = 0;
	}

	Point_2::Point_2(long double x, long double y) {
		this->x = x;
		this->y = y;
	}

	bool Point_2::operator== (const Point_2 & p) const {
		return Compare::compare(this->x, p.x) == 0 && Compare::compare(this->y, p.y) == 0;
	}

	bool Point_2::operator!= (const Point_2 & p) const {
		return !(*this == p);
	}

	void Point_2::show() const {
		printf("point[{%.10Lf, %.10Lf}]\n", this->x, this->y);
	}

	long double Point_2::dist2(const Point_2 & p) const {
		return (p.x - this->x)*(p.x - this->x) + (p.y - this->y)*(p.y - this->y);
	}

	Point_2 Point_2::midPoint(const Point_2 & p) const {
		return Point_2((this->x + p.x)/2, (this->y + p.y)/2);
	}
}