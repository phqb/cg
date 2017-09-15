#include "../include/convex_polygon.h"

namespace cg {
	ConvexPolygon::ConvexPolygon() {}

	ConvexPolygon::~ConvexPolygon() {
		this->points.clear();
	}

	void ConvexPolygon::show() const {
		printf("polygon[\n");
		this->points.begin()->show();
		for (auto p = this->points.begin() + 1; p != this->points.end(); ++p) {
			printf(",");
			p->show();
		}
		printf("]\n");
	}
	
	void ConvexPolygon::addPoint(const Point_2 & p) {
		this->points.push_back(p);
	}

	long double ConvexPolygon::area() const {
		if (this->points.size() <= 2)
			return 0;
		long double c1 = 0, c2 = 0;
		for (auto itr = this->points.begin(); itr != this->points.end() - 1; itr++) {
			c1 += itr->x*(itr + 1)->y;
			c2 += itr->y*(itr + 1)->x;
		}
		c1 += this->points.rbegin()->x*this->points.begin()->y;
		c2 += this->points.rbegin()->y*this->points.begin()->x;
		return (c1 - c2)/2;
	}

	void ConvexPolygon::sortCCW() {
		iter_swap(
			min_element(
				this->points.begin(), 
				this->points.end(), 
				[](const Point_2 & a, const Point_2 & b) { 
					return (a.y < b.y) || (Compare::compare(a.y, b.y) == 0 && a.x < b.x);
				}
			), 
			&this->points.at(0)
		);
		Point_2 p0 = this->points.at(0);
		sort(
			this->points.begin() + 1, 
			this->points.end(),
			[&p0](const Point_2 & a, const Point_2 & b) { 
				// int ori = a.orientTo(b, p0);
				Vector_2 p0a(p0, a);
				Vector_2 ba(b, a);
				long double ori = p0a.crossProduct(ba);
				return (ori < 0) || (Compare::compare(ori, 0) == 0 && p0.dist2(a) < p0.dist2(b));
			}
		);
	}

	bool ConvexPolygon::contain(const Point_2 & p) const {
		if (this->points.size() <= 2)
			return false;
		Ray_2 r(Vector_2(p, Point_2(0, 0)), p);
		int count = 0;
		for (auto i = this->points.begin(); i != this->points.end() - 1; ++i) {
			Segment_2 s(*i, *(i + 1));
			if (s.contain(p))
				return true;
			if (r.intersect(s).first)
				count++;
		}
		{
			Segment_2 s(*this->points.rbegin(), *this->points.begin());
			if (s.contain(p))
				return true;
			if (r.intersect(s).first)
				count++;
		}
		return count%2 != 0;
	}
}