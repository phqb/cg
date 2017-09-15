#include <cstdio>

#include "../include/utils.h"
#include "../include/compare.h"

#include "../include/point_2.h"
#include "../include/segment_2.h"

int point_in_segment() {
    Utils utils;
    for (long test = 0; test < 1000000; ++test) {
        cg::Point_2 pointA(utils.randFloat(1000), utils.randFloat(1000));
        cg::Point_2 pointB(utils.randFloat(1000), utils.randFloat(1000));
        cg::Segment_2 s(pointA, pointB);
        cg::Point_2 midPoint = pointA.midPoint(pointB);
        if (!s.contain(midPoint)) {
            printf("Failed at test:\n");
            s.show();
            printf("Start point: "); pointA.show();
            printf("End point: "); pointB.show();
            midPoint.show();
            printf("point in segment but program don't think so\n");
            return -1;
        }
        {
            long double x = pointA.x + (pointA.x < pointB.x ? -2*Compare::EPSILON : 2*Compare::EPSILON);
            cg::Point_2 notContained(x, (-s.a*x - s.c)/s.b);
            if (s.contain(notContained)) {
                printf("Failed at test:\n");
                s.show();
                printf("Start point: "); pointA.show();
                printf("End point: "); pointB.show();
                midPoint.show();
                printf("point NOT in segment but program don't think so\n");
                return -1;
            }
        }
        {
            long double x = pointB.x + (pointA.x < pointB.x ? 2*Compare::EPSILON : -2*Compare::EPSILON);
            cg::Point_2 notContained(x, (-s.a*x - s.c)/s.b);
            if (s.contain(notContained)) {
                printf("Failed at test:\n");
                s.show();
                printf("Start point: "); pointA.show();
                printf("End point: "); pointB.show();
                midPoint.show();
                printf("point NOT in segment but program don't think so\n");
                return -1;
            }
        }
    }
    return 0;
}