#include "../include/utils.h"

Utils::Utils() {
    srand(time(0));
}

int Utils::randInt(int absMax) {
    return rand()%absMax - rand()%absMax;
}

long double Utils::randFloat(int absMax) {
    int a = randInt(absMax);
    int b;
    do {
        b = randInt(absMax);
    } while (b == 0);
    return (long double)a/b;
}