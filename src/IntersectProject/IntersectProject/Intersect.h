#pragma once
#include <iostream>
#include <unordered_set>
#include <list>
#include <string>
#include <math.h>
class Line {
private:
    std::unordered_set <double> intersections;    //�洢һ��ֱ��������ͼ�����еĽ���
public:
    double a;
    double b;
    double c;
    Line(double a, double b, double c);
    int addIntersection(double x, double y);
};

class Circle {
private:
    std::unordered_set<double> intersections;    //�洢��Բ������ͼ�����еĽ���

public:
    double x;
    double y;
    double r;
    Circle(double x, double y, double r);
    int addIntersection(double x2, double y2);
};