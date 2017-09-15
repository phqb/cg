#ifndef COMPARE_H
#define COMPARE_H

#include <cmath>

class Compare {
    public:
        static const long double EPSILON;
        static const long double ARC_EPSILON;
        static int compare(const long double a, const long double b);
        static int arcCompare(const long double a, const long double b);
};

#endif