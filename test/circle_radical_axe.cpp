#include <cstdio>

#include "../include/utils.h"
#include "../include/compare.h"

#include "../include/circle.h"
#include "../include/line.h"

int circle_radical_axe() {
    Utils utils;
    for (long test = 0; test < 1000000; ++test) {
        cg::Circle c1(cg::Point(utils.randFloat(1000), utils.randFloat(1000)), abs(utils.randFloat(1000)));
        cg::Circle c2(cg::Point(utils.randFloat(1000), utils.randFloat(1000)), abs(utils.randFloat(1000)));
        if (c1.contain(c2) || c2.contain(c1)) {
            test--;
            continue;
        }
        cg::Line l = c1.radicalAxe(c2);
        auto p = l.intersect(cg::Line(c1.p, c2.p));
        if (!p.first || Compare::compare(c1.dist2(p.second), c2.dist2(p.second)) != 0) {
            printf("Failed at test:\n");
            c1.show();
            c2.show();
            l.show();
            p.second.show();
            return -1;
        }
    }
    return 0;
}