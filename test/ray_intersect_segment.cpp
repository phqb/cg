#include <cstdio>

#include "../include/utils.h"
#include "../include/compare.h"

#include "../include/segment_2.h"
#include "../include/ray_2.h"

int ray_intersect_segment() {
    Utils utils;
    for (long test = 0; test < 1000000; ++test) {
        {
            cg::Point_2 pointA(utils.randFloat(1000), utils.randFloat(1000));
            cg::Point_2 pointB(utils.randFloat(1000), utils.randFloat(1000));
            cg::Segment_2 s(pointA, pointB);
            cg::Point_2 midPoint = pointA.midPoint(pointB);
            cg::Vector_2 v(midPoint, pointA);
            v.rotate(cg::Point_2(0, 0), M_PI/2);
            cg::Ray_2 r(cg::Vector_2(-v.x, -v.y), v.getEndPoint_2(midPoint));
            auto inter = r.intersect(s);
            if (!inter.first) {
                printf("Failed at test:\n");
                s.show();
                printf("ray start point: ");
                r.startPoint_2.show();
                printf("ray dir: ");
                r.dir.show();
                printf("ray and segment have intersection but program don't think so\n");
                return -1;
            }
            if (!s.contain(inter.second) || !r.contain(inter.second)) {
                printf("Failed at test:\n");
                s.show();
                printf("ray start point: ");
                r.startPoint_2.show();
                printf("ray dir: ");
                r.dir.show();
                inter.second.show();
                printf("wrong intersection\n");
                return -1;
            }
        }
        {
            cg::Point_2 pointA(utils.randFloat(1000), utils.randFloat(1000));
            cg::Point_2 pointB(utils.randFloat(1000), utils.randFloat(1000));
            cg::Segment_2 s(pointA, pointB);
            cg::Point_2 midPoint = pointA.midPoint(pointB);
            cg::Vector_2 v(midPoint, pointA);
            v.rotate(cg::Point_2(0, 0), M_PI/2);
            cg::Ray_2 r(v, v.getEndPoint_2(midPoint));
            auto inter = r.intersect(s);
            if (inter.first) {
                printf("Failed at test:\n");
                s.show();
                printf("ray start point: ");
                r.startPoint_2.show();
                printf("ray dir: ");
                r.dir.show();
                printf("ray and segment DON'T have intersection but program don't think so\n");
                return -1;
            }
        }
    }
    return 0;
}