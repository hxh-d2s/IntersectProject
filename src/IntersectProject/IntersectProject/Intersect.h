#pragma once
#include <iostream>
#include <unordered_set>
#include <list>
#include <string>
#include <math.h>
class Line {
private:
    std::unordered_set <double> intersections;    //存储一条直线与其他图形所有的交点
public:
    double a;
    double b;
    double c;
    Line(double a, double b, double c);
    int addIntersection(double x, double y);
};

class Circle {
private:
    std::unordered_set<double> intersections;    //存储个圆与其他图形所有的交点

public:
    double x;
    double y;
    double r;
    Circle(double x, double y, double r);
    int addIntersection(double x2, double y2);
};