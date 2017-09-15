#include "../include/halfplane.h"

namespace cg {
	HalfPlane::HalfPlane() {}

	HalfPlane::HalfPlane(const Line_2 & l, int side) {
		this->a = l.a;
		this->b = l.b;
		this->c = l.c;
		this->side = side;
	}

	HalfPlane::HalfPlane(const Point_2 & a, const Point_2 & b, int side) : Line_2(a, b) {
		this->side = side;
	}

	HalfPlane::HalfPlane(long double a, long double b, long double c, int side) : Line_2(a, b, c) {
		this->side = side;
	}

	bool HalfPlane::contain(const Point_2 & p) const {
		long double c = this->a*p.x + this->b*p.y + this->c;
		return Compare::compare(c, 0) == 0 || c*this->side > 0;
	}

	void HalfPlane::faceTo(const Point_2 & p) {
		if (!this->contain(p)) this->side *= -1;
	}

	ConvexPolygon HalfPlane::halfPlanesIntersect(const std::vector<HalfPlane> & hl) {
		ConvexPolygon pl;
		for (auto i = hl.begin(); i != hl.end() - 1; ++i)
			for (auto j = i + 1; j != hl.end(); ++j) {
				std::pair<bool, Point_2> inter = i->intersect(*j);
				if (inter.first) {
					bool allIn = true;
					for (auto h = hl.begin(); h != hl.end(); ++h)
						if (!h->contain(inter.second)) {
							allIn = false;
							break;
						}
					if (allIn)
						pl.addPoint(inter.second);
				}
			}
		pl.sortCCW();
		return pl;
	}
}