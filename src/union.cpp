#include "../include/union.h"

namespace cg {
    double unionArea(const Circle & c, const Triangle & trig) {
        long pointsInCircleCount = 0;
        for (long p = 0; p < 3; ++p)
            if (c.containWithin(trig.points[p]))
                pointsInCircleCount++;

        long edgesIntersectCircleCount = 0;
        long edgesIntersectCircle[3];
        for (long e = 0; e < 3; ++e)
            if (c.intersect(trig.edges[e]).first > 0)
                edgesIntersectCircle[edgesIntersectCircleCount++] = e;

        long edgesInCircleCount = 0;
        long edgesInCircle[3];
        for (long e = 0; e < 3; ++e)
            if (c.containWithin(trig.edges[e]))
                edgesInCircle[edgesInCircleCount++] = e;

        HalfPlane edgeHalfPlanes[3] = { 
            HalfPlane(trig.points[0], trig.points[1], 1), 
            HalfPlane(trig.points[1], trig.points[2], 1), 
            HalfPlane(trig.points[2], trig.points[0], 1) 
        };
        for (long hl = 0; hl < 3; ++hl)
            if (!edgeHalfPlanes[hl].contain(trig.edgesOppositePoint[hl]))
                edgeHalfPlanes[hl].side *= -1;

        std::pair<long, long> count = make_pair(pointsInCircleCount, edgesIntersectCircleCount + edgesInCircleCount);
            
        switch (count) {
            case std::make_pair(0, 0):
                if (edgeHalfPlanes[0].contain(c.p) && edgeHalfPlanes[1].contain(c.p) && edgeHalfPlanes[2].contain(c.p))
                    return c.area();
                else
                    return 0;
            case std::make_pair(0, 1):
                return unionArea(c, edgeHalfPlanes[edgesIntersectCircle[0]]);
            case std::make_pair(0, 2):
                return
                    trig.area() + c.area() - (
                        (c.area() - unionArea(c, edgeHalfPlanes[edgesIntersectCircle[0]])) +
                        (c.area() - unionArea(c, edgeHalfPlanes[edgesIntersectCircle[1]]))
                    ) - trig.area();
            case std::make_pair(0, 3):
                return
                    trig.area() + c.area() - (
                        (c.area() - unionArea(c, edgeHalfPlanes[edgesIntersectCircle[0]])) +
                        (c.area() - unionArea(c, edgeHalfPlanes[edgesIntersectCircle[1]])) +
                        (c.area() - unionArea(c, edgeHalfPlanes[edgesIntersectCircle[2]]))
                    ) - trig.area();
            case std::make_pair(1, 2): {
                Segment s1 = edges[edgesIntersectCircle[0]];
                Segment s2 = edges[edgesIntersectCircle[1]];
                Triangle areaTrig(c.intersect(s1).second.first, c.intersect(s2).second.first, Line(s1.p1, s1.p2).intersect(Line(s2.p1, s2.p2)).second);
                HalfPlane hl(areaTrig.points[0], areaTrig.points[1],    )
            }
            case std::make_pair(3, 3):
                return trig.area();
        }
    }

    double unionArea(const Circle & c, const Polygon & pl) {
        if (pl.points.size() <= 2)
            return 0;
        double area = 0;
        for (auto p = pl.points.begin() + 1; p != pl.points.end() - 1; ++p)
            area += unionArea(c, *pl.points.begin(), *p, *(p + 1));
        return area;
    }

    double unionArea(const Circle & c, const HalfPlane & hl) {
        auto inters = c.intersect(hl);
        if (inters.first < 2)
            return 0;
        double angle = Vector2(c.p, inters.second.first).angle(Vector2(c.p, inters.second.second));
        if (hl.contain(c.p))
            return c.area() - c.segmentArea(angle);
        else 
            return c.segmentArea(angle);
    }
}