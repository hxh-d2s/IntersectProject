#include "Intersect.h"
Line::Line(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}
int Line::addIntersection(double x, double y) {
    std::pair<std::unordered_set<double>::iterator, bool> suc;
    if (b == 0)
        suc = intersections.insert(y);
    else
        suc = intersections.insert(x);
    if (suc.second == true)
        return 1;
    else
        return 0;
}

