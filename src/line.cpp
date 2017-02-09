#include "../include/line.h"

namespace cg {
	Line::Line() {}

	Line::Line(double a, double b, double c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	Line::Line(const Point & a, const Vector2 & v) {
		this->a = v.x;
		this->b = v.y;
		this->c = this->a*(-a.x) + this->b*(-a.y);
	}

	Line::Line(const Point & a, const Point & b) {
		Vector2 v = Vector2(a, b).getNorm();
		Line l = Line(a, v);
		this->a = l.a;
		this->b = l.b;
		this->c = l.c;
	}

	void Line::show() const {
		printf("%.10lfx + %.10lfy + %.10lf = 0\n", this->a, this->b, this->c);
	}

	bool Line::contain(const Point & p) const {
		return Compare::compare(this->a*p.x + this->b*p.y + this->c, 0) == 0;
	}

	double Line::dist(const Point & p) const {
		return fabs(this->a*p.x + this->b*p.y + this->c)/sqrt(this->a*this->a + this->b*this->b);
	}

	std::pair<bool, Point> Line::intersect(const Line & l) const {
		double a1 = this->a, b1 = this->b, c1 = -this->c;
		double a2 = l.a, b2 = l.b, c2 = -l.c;
		double d = a1*b2 - a2*b1;
		double dx = c1*b2 - c2*b1;
		double dy = a1*c2 - a2*c1;
		if (d != 0)
			return std::make_pair(true, Point(dx/d, dy/d));
		else
			return std::make_pair(false, Point());
	}

	Line Line::perpendicular(const Point & p) const {
		// Point endPoint(p.x + 1, (-this->a*(p.x + 1) - this->c)/this->b);
		// return Line(p, Vector2(p, endPoint));
		return Line(p, Vector2(-this->b, this->a));
	}
}