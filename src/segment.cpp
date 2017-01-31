#include "../include/segment.h"

Segment::Segment(const Point & a, const Point & b) : Line(a, b) {
	this->p1 = a;
	this->p2 = b;
}

Line Segment::perpendicularBisector() const {
	Point m = this->p1.midPoint(p2);
	Vector2 v(m, this->p1);
	return Line(m, v);
}

bool Segment::contain(const Point & p) const {
	Line segLine(this->p1, this->p2);
	if (!segLine.contain(p))
		return false;
	if (fabs(this->p1.x - this->p2.x) > fabs(this->p1.y - this->p2.y))
		return this->p1.x < this->p2.x ?
			Compare::compare(this->p1.x, p.x) <= 0 && Compare::compare(p.x, this->p2.x) <= 0 :
			Compare::compare(this->p2.x, p.x) <= 0 && Compare::compare(p.x, this->p1.x) <= 0;
	else
		return this->p1.y < this->p2.y ?
			Compare::compare(this->p1.y, p.y) <= 0 && Compare::compare(p.y, this->p2.y) <= 0 :
			Compare::compare(this->p2.y, p.y) <= 0 && Compare::compare(p.y, this->p1.y) <= 0;
}