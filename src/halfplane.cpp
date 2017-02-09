#include "../include/halfplane.h"

namespace cg {
	HalfPlane::HalfPlane() {}

	HalfPlane::HalfPlane(const Line & l, int side) {
		this->a = l.a;
		this->b = l.b;
		this->c = l.c;
		this->side = side;
	}

	HalfPlane::HalfPlane(const Point & a, const Point & b, int side) : Line(a, b) {
		this->side = side;
	}

	HalfPlane::HalfPlane(double a, double b, double c, int side) : Line(a, b, c) {
		this->side = side;
	}

	bool HalfPlane::contain(const Point & p) const {
		double c = this->a*p.x + this->b*p.y + this->c;
		return Compare::compare(c, 0) == 0 || c*this->side > 0;
	}

	Polygon HalfPlane::halfPlanesIntersect(const std::vector<HalfPlane> & hl) {
		Polygon pl;
		for (auto i = hl.begin(); i != hl.end() - 1; i++)
			for (auto j = i + 1; j != hl.end(); j++) {
				std::pair<bool, Point> inter = i->intersect(*j);
				if (inter.first) {
					bool allIn = true;
					for (auto h : hl)
						if (!h.contain(inter.second)) {
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