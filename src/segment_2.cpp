#include "../include/segment_2.h"

namespace cg {
	Segment_2::Segment_2() {}

	Segment_2::Segment_2(const Point_2 & a, const Point_2 & b) : Line_2(a, b) {
		this->p1 = a;
		this->p2 = b;
	}

	long double Segment_2::length() const {
		return sqrtl(this->p1.dist2(this->p2));
	}

	Line_2 Segment_2::perpendicularBisector() const {
		Point_2 m = this->p1.midPoint(p2);
		Vector_2 v(m, this->p1);
		return Line_2(m, v);
	}

	bool Segment_2::contain(const Point_2 & p) const {
		Line_2 segLine_2(this->p1, this->p2);
		if (!segLine_2.contain(p))
			return false;
		if (fabsl(this->p1.x - this->p2.x) > fabsl(this->p1.y - this->p2.y))
			return this->p1.x < this->p2.x ?
				Compare::compare(this->p1.x, p.x) <= 0 && Compare::compare(p.x, this->p2.x) <= 0 :
				Compare::compare(this->p2.x, p.x) <= 0 && Compare::compare(p.x, this->p1.x) <= 0;
		else
			return this->p1.y < this->p2.y ?
				Compare::compare(this->p1.y, p.y) <= 0 && Compare::compare(p.y, this->p2.y) <= 0 :
				Compare::compare(this->p2.y, p.y) <= 0 && Compare::compare(p.y, this->p1.y) <= 0;
	}
}