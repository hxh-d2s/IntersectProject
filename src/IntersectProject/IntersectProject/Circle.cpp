#include "Intersect.h"
Circle::Circle(double x, double y, double r) {
    this->x = x;
    this->y = y;
    this->r = r;
}

int Circle::addIntersection(double x2, double y2) {
    double m = atan2(y2 - y, x2 - x);
    std::pair<std::unordered_set<double>::iterator, bool> suc;
    suc = intersections.insert(m);
    if (suc.second == true)
        return 1;
    else
        return 0;
}