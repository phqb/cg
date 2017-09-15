#include "../include/circle.h"

namespace cg {
	Circle::Circle() {}

	Circle::Circle(const Point_2 & p, long double r) {
		this->p = p;
		this->r = r;
	}

	void Circle::show() const {
		printf("circle[");
		this->p.show();
		printf(", %Lf\n", this->r);
		printf("]\n");
	}

	long double Circle::dist2(const Point_2 & p) const {
		return this->p.dist2(p) - this->r*this->r;
	}

	Line_2 Circle::radicalAxe(const Circle & c) const {
		Vector_2 p1p2(this->p, c.p);
		long double l = sqrtl(this->p.dist2(c.p));
		long double l1 = (l*l + this->r*this->r - c.r*c.r)/(2*l);
		Vector_2 vl1(p1p2);
		vl1.resize(l1);
		Point_2 midPoint = vl1.getEndPoint_2(this->p);
		Line_2 ret(midPoint, vl1);
		return ret;
	}

	bool Circle::contain(const Point_2 & p) const {
		return Compare::compare(this->p.dist2(p), this->r*this->r) <= 0;
	}

	bool Circle::containWithin(const Point_2 & p) const {
		return Compare::compare(this->p.dist2(p), this->r*this->r) < 0;
	}

	bool Circle::containOn(const Point_2 & p) const {
		return Compare::compare(this->p.dist2(p), this->r*this->r) == 0;
	}

	bool Circle::contain(const Segment_2 & s) const {
		return this->contain(s.p1) && this->contain(s.p2);
	}

	bool Circle::containWithin(const Segment_2 & s) const {
		return this->containWithin(s.p1) && this->containWithin(s.p2);
	}

	bool Circle::contain(const Circle & c) const {
		long double d = sqrtl(this->p.dist2(c.p));
		return Compare::compare(this->r - c.r, d) >= 0;
	}

	std::pair<int, std::pair<Point_2, Point_2>> Circle::intersect(const Line_2 & l) const {
		Line_2 perLine_2 = l.perpendicular(this->p);
		auto inter = l.intersect(perLine_2);
		long double d2 = this->p.dist2(inter.second);
		if (Compare::compare(this->r*this->r, d2) == 0)
			return std::make_pair(1, std::make_pair(inter.second, inter.second));
		else if (Compare::compare(this->r*this->r, d2) > 0) {
			long double d = sqrtl(this->r*this->r - d2);
			Vector_2 p(-l.b, l.a);
			p.resize(d);
			Point_2 i1 = p.getEndPoint_2(inter.second);
			p.rotate(Point_2(0, 0), M_PI);
			Point_2 i2 = p.getEndPoint_2(inter.second);
			return std::make_pair(2, std::make_pair(i1, i2));
		} else
			return std::make_pair(0, std::make_pair(Point_2(), Point_2()));
	}

	std::pair<int, std::pair<Point_2, Point_2>> Circle::intersect(const Segment_2 & s) const {
		Line_2 sLine_2(s.p1, s.p2);
		auto inters = this->intersect(sLine_2);
		if (inters.first == 0 || (s.contain(inters.second.first) && s.contain(inters.second.second)))
			return inters;
		else if (s.contain(inters.second.first))
			return std::make_pair(1, std::make_pair(inters.second.first, inters.second.first));
		else if (s.contain(inters.second.second))
			return std::make_pair(1, std::make_pair(inters.second.second, inters.second.first));
		else
			return std::make_pair(0, std::make_pair(Point_2(), Point_2()));
	}

	std::pair<int, std::pair<Point_2, Point_2>> Circle::intersect(const Ray_2 & r) const {
		Line_2 rayLine_2(r.startPoint_2, r.dir.getEndPoint_2(r.startPoint_2));
		auto inters = this->intersect(rayLine_2);
		if (inters.first == 0)
			return std::make_pair(0, std::make_pair(Point_2(), Point_2()));
		if (inters.first == 1)
			return 
				r.contain(inters.second.first) ?
				std::make_pair(1, inters.second) :
				std::make_pair(0, std::make_pair(Point_2(), Point_2()));
		return inters;
	}

	long double Circle::area() const {
		return M_PI*this->r*this->r;
	}

	long double Circle::segmentArea(long double rad) const {
		return this->r*this->r*(rad - sinl(rad))/2;
	}
}