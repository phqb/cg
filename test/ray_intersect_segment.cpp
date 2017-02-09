#include <cstdio>

#include "../include/utils.h"
#include "../include/compare.h"

#include "../include/segment.h"
#include "../include/ray.h"

int ray_intersect_segment() {
    Utils utils;
    for (long test = 0; test < 1000000; ++test) {
        {
            cg::Point pointA(utils.randFloat(1000), utils.randFloat(1000));
            cg::Point pointB(utils.randFloat(1000), utils.randFloat(1000));
            cg::Segment s(pointA, pointB);
            cg::Point midPoint = pointA.midPoint(pointB);
            cg::Vector2 v(midPoint, pointA);
            v.rotate(cg::Point(0, 0), M_PI/2);
            cg::Ray r(cg::Vector2(-v.x, -v.y), v.getEndPoint(midPoint));
            auto inter = r.intersect(s);
            if (!inter.first) {
                printf("Failed at test:\n");
                s.show();
                printf("ray start point: ");
                r.startPoint.show();
                printf("ray dir: ");
                r.dir.show();
                printf("ray and segment have intersection but program don't think so\n");
                return -1;
            }
            if (!s.contain(inter.second) || !r.contain(inter.second)) {
                printf("Failed at test:\n");
                s.show();
                printf("ray start point: ");
                r.startPoint.show();
                printf("ray dir: ");
                r.dir.show();
                inter.second.show();
                printf("wrong intersection\n");
                return -1;
            }
        }
        {
            cg::Point pointA(utils.randFloat(1000), utils.randFloat(1000));
            cg::Point pointB(utils.randFloat(1000), utils.randFloat(1000));
            cg::Segment s(pointA, pointB);
            cg::Point midPoint = pointA.midPoint(pointB);
            cg::Vector2 v(midPoint, pointA);
            v.rotate(cg::Point(0, 0), M_PI/2);
            cg::Ray r(v, v.getEndPoint(midPoint));
            auto inter = r.intersect(s);
            if (inter.first) {
                printf("Failed at test:\n");
                s.show();
                printf("ray start point: ");
                r.startPoint.show();
                printf("ray dir: ");
                r.dir.show();
                printf("ray and segment DON'T have intersection but program don't think so\n");
                return -1;
            }
        }
    }
    return 0;
}