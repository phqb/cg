#include <cstdio>

#include "../include/utils.h"
#include "../include/compare.h"

#include "../include/point_2.h"
#include "../include/line_2.h"

int point_in_line() {
    Utils utils;
    for (long test = 0; test < 1000000; ++test) {
        cg::Point_2 pointA(utils.randFloat(1000), utils.randFloat(1000));
        cg::Point_2 pointB(utils.randFloat(1000), utils.randFloat(1000));
        cg::Line_2 line(pointA, pointB);
        if (!line.contain(pointA)) {
            printf("Failed at test:\n");
            pointA.show();
            line.show();
            printf("point in line but program don't think so\n");
            return -1;
        }
        if (!line.contain(pointB)) {
            printf("Failed at test:\n");
            pointB.show();
            line.show();
            printf("point in line but program don't think so\n");
            return -1;
        }
        cg::Line_2 anotherLine_2(line.a, line.b, line.c + 2*Compare::EPSILON);
        long double x = utils.randFloat(1000);
        cg::Point_2 notContained(x, (-anotherLine_2.a*x - anotherLine_2.c)/anotherLine_2.b);
        if (line.contain(notContained)) {
            printf("Failed at test:\n");
            notContained.show();
            line.show();
            printf("point NOT in line but program don't think so\n");
            return -1;
        }
    }
    return 0;
}