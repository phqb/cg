#ifndef UTILS_H
#define UTILS_H

#include <ctime>
#include <cstdlib>

class Utils {
    public:
        Utils();
        int randInt(int absMax);
        double randFloat(int absMax);
};

#endif