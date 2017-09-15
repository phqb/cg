#include "../include/ray_2.h"

namespace cg {
	Ray_2::Ray_2() {}

	Ray_2::Ray_2(const Vector_2 & dir, const Point_2 & startPoint_2) {
		this->dir = dir;
		this->startPoint_2 = startPoint_2;
	}

	std::pair<bool, Point_2> Ray_2::intersect(const Segment_2 & s) const {
		Line_2 rayLine_2(this->startPoint_2, this->dir.getEndPoint_2(this->startPoint_2));
		Line_2 segLine_2(s.p1, s.p2);
		auto inter = rayLine_2.intersect(segLine_2);
		if (!inter.first)
			return std::make_pair(false, Point_2());
		if (this->contain(inter.second) && s.contain(inter.second))
			return inter;
		else
			return std::make_pair(false, Point_2());
	}

	bool Ray_2::contain(const Point_2 & p) const {
		Line_2 rayLine_2(this->startPoint_2, this->dir.getEndPoint_2(this->startPoint_2));
		if (!rayLine_2.contain(p))
			return false;
		Vector_2 v(this->startPoint_2, p);
		return Compare::compare(this->dir.angle(v), 0) == 0;
	}
}