#include <cstdio>

#include "../include/utils.h"
#include "../include/compare.h"

#include "../include/point_2.h"
#include "../include/line_2.h"

int line_intersect_line() {
    Utils utils;
    for (long test = 0; test < 1000000; ++test) {
        {
            cg::Line_2 line_a(cg::Point_2(utils.randFloat(1000), utils.randFloat(1000)), cg::Point_2(utils.randFloat(1000), utils.randFloat(1000)));
            cg::Line_2 line_b(-line_a.b, line_a.a, utils.randFloat(1000));
            auto inter = line_a.intersect(line_b);
            if (!inter.first || !line_a.contain(inter.second) || !line_b.contain(inter.second)) {
                printf("Failed at test:\n");
                line_a.show();
                line_b.show();
                if (!inter.first)
                    printf("lines have intersection but program don't think so\n");
                else
                    printf("wrong intersection\n");
                return -1;
            }
        }
        {
            cg::Line_2 line_a(cg::Point_2(utils.randFloat(1000), utils.randFloat(1000)), cg::Point_2(utils.randFloat(1000), utils.randFloat(1000)));
            cg::Line_2 line_b(line_a.a, line_a.b, line_a.c + utils.randFloat(1000));
            auto inter = line_a.intersect(line_b);
            if (inter.first) {
                printf("Failed at test:\n");
                line_a.show();
                line_b.show();
                printf("lines have NO intersection but program don't think so\n");
                return -1;
            }
        }
    }
    return 0;
}