#ifndef COMPARE_H
#define COMPARE_H

#include <math.h>

using namespace std;

class Compare {
    public:        
        static int compare(const double a, const double b);

    private:
        static const double EPSILON;
};

#endif