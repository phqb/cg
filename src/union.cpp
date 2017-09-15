#include "../include/union.h"

namespace cg {
    long double unionArea(const Circle & c, const Triangle & trig) {
        long double result;

        Point_2 pointsInCircle[3];
        int pointsInCircleCount = 0;
        Point_2 pointsOutCircle[3];
        int pointsOutCircleCount = 0;
        Point_2 pointsOnCircle[3];
        int pointsOnCircleCount = 0;
        int edgesInterCircleCount = 0;
        HalfPlane halfPlanesInterCircle[3];
        int halfPlanesInterCircleCount = 0;
        Segment_2 edgesInCircle[3];
        int edgesInCircleCount = 0;
        std::pair<int, std::pair<Point_2, Point_2>> intersCircle[3];
        int intersCircleCount = 0;
        for (long p = 0; p < 3; ++p) {
            if (c.containWithin(trig.points[p]))
                pointsInCircle[pointsInCircleCount++] = trig.points[p];
            else if (c.containOn(trig.points[p]))
                pointsOnCircle[pointsOnCircleCount++] = trig.points[p];
            else
                pointsOutCircle[pointsOutCircleCount++] = trig.points[p];
        }
        for (long e = 0; e < 3; ++e) {
            if (c.intersect(trig.edges[e]).first > 0) {
                auto inter = c.intersect(trig.edges[e]);
                if (inter.first > 0) {
                    edgesInterCircleCount++;
                    intersCircle[intersCircleCount++] = inter;
                    halfPlanesInterCircle[halfPlanesInterCircleCount++] = trig.edgeHalfPlanes[e];
                }
            }
            if (c.containWithin(trig.edges[e]))
                edgesInCircle[edgesInCircleCount++] = trig.edges[e];
        }

        if (pointsOnCircleCount == 3) {
            result = Triangle(pointsOnCircle[0], pointsOnCircle[1], pointsOnCircle[2]).area();
        } else if (pointsOnCircleCount == 2) {
            if (pointsInCircleCount == 1)
                result = Triangle(pointsOnCircle[0], pointsOnCircle[1], pointsInCircle[0]).area();
            else
                result = unionArea(c, halfPlanesInterCircle[0]);
        } else if (pointsOnCircleCount == 1) {
            if (pointsInCircleCount == 2)
                result = Triangle(pointsOnCircle[0], pointsInCircle[0], pointsInCircle[1]).area();
            else if (pointsOutCircleCount == 2)
                result = 0;
            else {
                Point_2 inter = c.intersect(Segment_2(pointsInCircle[0], pointsOutCircle[0])).second.first;
                HalfPlane hl(pointsOnCircle[0], inter, 1);
                hl.faceTo(pointsOutCircle[0]);
                Triangle areaTrig(pointsOnCircle[0], pointsInCircle[0], inter);
                result = areaTrig.area() + unionArea(c, hl);
            }
        } else {
            std::tuple<int, int, int> count = std::make_tuple(
                pointsInCircleCount, 
                edgesInterCircleCount,
                edgesInCircleCount
            );
            if (count == std::make_tuple(0, 0, 0)) {
                result = c.area();
                for (long hl = 0; hl < 3; ++hl)
                    if (!trig.edgeHalfPlanes[hl].contain(c.p)) {
                        result = 0;
                        break;
                    }
            } else if (count == std::make_tuple(0, 1, 0)) {
                result = unionArea(c, halfPlanesInterCircle[0]);
            } else if (count == std::make_tuple(0, 2, 0)) {
                long double segArea1 = c.area() - unionArea(c, halfPlanesInterCircle[0]);
                long double segArea2 = c.area() - unionArea(c, halfPlanesInterCircle[1]);
                result = c.area() - (segArea1 + segArea2);
            } else if (count == std::make_tuple(0, 3, 0)) {
                long double segArea1 = c.area() - unionArea(c, halfPlanesInterCircle[0]);
                long double segArea2 = c.area() - unionArea(c, halfPlanesInterCircle[1]);
                long double segArea3 = c.area() - unionArea(c, halfPlanesInterCircle[2]);
                result = c.area() - (segArea1 + segArea2 + segArea3);
            } else if (count == std::make_tuple(1, 2, 0)) {
                Triangle areaTrig(pointsInCircle[0], intersCircle[0].second.first, intersCircle[1].second.first);
                HalfPlane hl(intersCircle[0].second.first, intersCircle[1].second.first, 1);
                hl.faceTo(pointsInCircle[0]);
                result = areaTrig.area() + c.area() - unionArea(c, hl);
            } else if (count == std::make_tuple(1, 3, 0)) {
                std::pair<Point_2, Point_2> twoIntersPoints;
                Point_2 oneInterPoints[3];
                int oneInterPointsCount = 0;
                for (int inter = 0; inter < 3; ++inter) {
                    if (intersCircle[inter].first == 2)
                        twoIntersPoints = intersCircle[inter].second;
                    if (intersCircle[inter].first == 1)
                        oneInterPoints[oneInterPointsCount++] = intersCircle[inter].second.first;
                }
                Triangle areaTrig(pointsInCircle[0], oneInterPoints[0], oneInterPoints[1]);
                HalfPlane hl1(oneInterPoints[0], oneInterPoints[1], 1);
                hl1.faceTo(pointsInCircle[0]);
                HalfPlane hl2(twoIntersPoints.first, twoIntersPoints.second, 1);
                hl2.faceTo(pointsInCircle[0]);
                result = areaTrig.area() + (c.area() - unionArea(c, hl1)) - (c.area() - unionArea(c, hl2));
            } else if (count == std::make_tuple(2, 2, 1)) {
                ConvexPolygon areaQuad;
                areaQuad.addPoint(intersCircle[0].second.first);
                areaQuad.addPoint(intersCircle[1].second.first);
                areaQuad.addPoint(edgesInCircle[0].p1);
                areaQuad.addPoint(edgesInCircle[0].p2);
                areaQuad.sortCCW();
                HalfPlane hl(intersCircle[0].second.first, intersCircle[1].second.first, 1);
                hl.faceTo(pointsOutCircle[0]);
                result = areaQuad.area() + unionArea(c, hl);
            } else if (count == std::make_tuple(3, 0, 3)) {
                result = trig.area();
            } else
                result = 0;
        }

        return result;
    }

    long double unionArea(const Circle & c, const ConvexPolygon & pl) {
        if (pl.points.size() <= 2)
            return 0;
        long double area = 0;
        for (auto p = pl.points.begin() + 1; p != pl.points.end() - 1; ++p) {
            Triangle trig(*pl.points.begin(), *p, *(p + 1));
            area += unionArea(c, trig);
        }
        return area;
    }

    long double unionArea(const Circle & c, const HalfPlane & hl) {
        auto inters = c.intersect(hl);
        if (inters.first == 0)
            return 0;
        long double angle = Vector_2(c.p, inters.second.first).angle(Vector_2(c.p, inters.second.second));
        if (hl.contain(c.p))
            return c.area() - c.segmentArea(angle);
        else 
            return c.segmentArea(angle);
    }
}