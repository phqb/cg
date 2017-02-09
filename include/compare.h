#ifndef COMPARE_H
#define COMPARE_H

#include <cmath>

class Compare {
    public:
        static const double EPSILON;
        static const double ARC_EPSILON;
        static int compare(const double a, const double b);
        static int arcCompare(const double a, const double b);
};

#endif