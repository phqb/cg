#include <cstdio>

#include "../include/utils.h"
#include "../include/compare.h"

#include "../include/line_2.h"
#include "../include/circle.h"

int circle_intersect_line() {
    Utils utils;
    for (long test = 0; test < 1000000; ++test) {
        cg::Circle c(cg::Point_2(utils.randFloat(1000), utils.randFloat(1000)), fabsl(utils.randFloat(1000)));
        cg::Line_2 l(cg::Point_2(utils.randFloat(1000), utils.randFloat(1000)), cg::Point_2(utils.randFloat(1000), utils.randFloat(1000)));
        auto inters = c.intersect(l);
        if (inters.first == 1) {
            if (!l.contain(inters.second.first) || Compare::compare(inters.second.first.dist2(c.p), c.r*c.r) != 0) {
                printf("Failed at test:\n");
                c.show();
                l.show();
                printf("wrong intersection\n");
                return -1;
            }
        } else if (inters.first == 2) {
            if (!l.contain(inters.second.first) || !l.contain(inters.second.second)) {
                printf("Failed at test:\n");
                c.show();
                l.show();
                printf("wrong intersection\n");
                return -1;
            }
        }
    }
    return 0;
}