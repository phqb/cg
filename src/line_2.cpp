#include "../include/line_2.h"

namespace cg {
	Line_2::Line_2() {
		this->a = this->b = this->c = 0;
	}

	Line_2::Line_2(long double a, long double b, long double c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	Line_2::Line_2(const Point_2 & a, const Vector_2 & v) {
		this->a = v.x;
		this->b = v.y;
		this->c = this->a*(-a.x) + this->b*(-a.y);
	}

	Line_2::Line_2(const Point_2 & a, const Point_2 & b) {
		Vector_2 v = Vector_2(a, b).getNorm();
		Line_2 l = Line_2(a, v);
		this->a = l.a;
		this->b = l.b;
		this->c = l.c;
	}

	void Line_2::show() const {
		printf("%.10Lfx + %.10Lfy + %.10Lf = 0\n", this->a, this->b, this->c);
	}

	bool Line_2::contain(const Point_2 & p) const {
		return Compare::compare(this->a*p.x + this->b*p.y + this->c, 0) == 0;
	}

	long double Line_2::dist(const Point_2 & p) const {
		return fabsl(this->a*p.x + this->b*p.y + this->c)/sqrtl(this->a*this->a + this->b*this->b);
	}

	std::pair<bool, Point_2> Line_2::intersect(const Line_2 & l) const {
		long double a1 = this->a, b1 = this->b, c1 = -this->c;
		long double a2 = l.a, b2 = l.b, c2 = -l.c;
		long double d = a1*b2 - a2*b1;
		long double dx = c1*b2 - c2*b1;
		long double dy = a1*c2 - a2*c1;
		if (d != 0)
			return std::make_pair(true, Point_2(dx/d, dy/d));
		else
			return std::make_pair(false, Point_2());
	}

	Line_2 Line_2::perpendicular(const Point_2 & p) const {
		// Point_2 endPoint_2(p.x + 1, (-this->a*(p.x + 1) - this->c)/this->b);
		// return Line_2(p, Vector_2(p, endPoint_2));
		return Line_2(p, Vector_2(-this->b, this->a));
	}
}