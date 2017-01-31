#include "../include/polygon.h"

double Polygon::area() const {
	double c1 = 0, c2 = 0;
	for (auto itr = this->begin(); itr != this->end() - 1; itr++) {
		c1 += itr->x*(itr + 1)->y;
		c2 += itr->y*(itr + 1)->x;
	}
	c1 += this->rbegin()->x*this->begin()->y;
	c2 += this->rbegin()->y*this->begin()->x;
	return (c1 - c2)/2;
}

void Polygon::sortCCW() {
	iter_swap(
		min_element(
			this->begin(), 
			this->end(), 
			[](const Point & a, const Point & b) { 
				return (a.y < b.y) || (Compare::compare(a.y, b.y) == 0 && a.x < b.x);
			}
		), 
		&this->at(0)
	);
	Point p0 = this->at(0);
	sort(
		this->begin() + 1, 
		this->end(),
		[&p0](const Point & a, const Point & b) { 
			// int ori = a.orientTo(b, p0);
			Vector2 p0a(p0, a);
			Vector2 ba(b, a);
			double ori = p0a.crossProduct(ba);
			return (ori < 0) || (Compare::compare(ori, 0) == 0 && p0.dist2(a) < p0.dist2(b));
		}
	);
}

bool Polygon::contain(const Point & p) const {
	Ray r(Vector2(p, Point(0, 0)), p);
	int count = 0;
	for (auto i = this->begin(); i != this->end() - 1; ++i) {
		Segment s(*i, *(i + 1));
		if (s.contain(p))
			return true;
		if (r.intersect(s).first)
			count++;
	}
	return count%2 != 0;
}