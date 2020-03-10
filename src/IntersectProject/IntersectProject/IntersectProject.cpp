// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Intersect.h"
using namespace std;

int main()
{
    list<Line> Linelist;
    list<Line>::iterator line_iter;
    list<Circle> Circlelist;
    list<Circle>::iterator circle_iter;

    int n, i, count;
    double x1, y1, x2, y2, r;
    double a, b, c;
    string type;

    cin >> n;
    count = 0;
    for (i = 0; i < n; i++) {
        cin >> type;
        if (type == "L") {
            cin >> x1 >> y1 >> x2 >> y2;
            //cout << "a line" << endl;
            a = y2 - y1;
            b = x1 - x2;
            c = x2 * y1 - x1 * y2;
            Line line(a, b, c);
            for (line_iter = Linelist.begin(); line_iter != Linelist.end(); line_iter++) {
                double a2 = line_iter->a;
                double b2 = line_iter->b;
                double c2 = line_iter->c;
                if (a * b2 == a2 * b) {     //判断是否平行
                    continue;
                }
                else {
                    double m = a * b2 - a2 * b;
                    double x = (c2 * b - c * b2) / m;
                    double y = (c * a2 - c2 * a) / m;
                    int sum = line_iter->addIntersection(x, y) + line.addIntersection(x, y);
                    if (sum == 2) {
                        count++;
                        //cout << x << " " << y << endl;
                    }
                }
            }
            for (circle_iter = Circlelist.begin(); circle_iter != Circlelist.end(); circle_iter++) {
                x2 = circle_iter->x;
                y2 = circle_iter->y;
                double r = circle_iter->r;
                double d = fabs((a * x2 + b * y2 + c) / sqrt(a * a + b * b));
                if (d > r)
                    continue;
                else {
                    double m = -a * a - b * b;
                    double x = ((a * y2 - b * x2) * b + c * a) / m;
                    double y = (c * b - (a * y2 - b * x2) * a) / m;
                    double t = sqrt((r * r - d * d) / (a * a + b * b));
                    int sum = circle_iter->addIntersection(x+b*t, y-a*t) + line.addIntersection(x+b*t, y-a*t);
                    if (sum == 2) {
                        count++;
                        //cout << x + b * t << " " << y - a * t  << endl;
                    }
                    sum = circle_iter->addIntersection(x-b*t, y+a*t) + line.addIntersection(x-b*t, y+a*t);
                    if (sum == 2) {
                        count++;
                        //cout << x - b * t << " " << y + a * t << endl;
                    }
                }
            }
            Linelist.push_back(line);
        }
        else if (type == "C") {
            cin >> x1 >> y1 >> r;
            //cout << "a circle" << endl;
            Circle circle(x1, y1, r);
            for (line_iter = Linelist.begin(); line_iter != Linelist.end(); line_iter++) {
                a = line_iter->a;
                b = line_iter->b;
                c = line_iter->c;
                double d = fabs((a * x1 + b * y1 + c) / sqrt(a * a + b * b));
                if (d > r)
                    continue;
                else if (d == r) {
                    double m = -a * a - b * b;
                    double x = ((a * y1 - b * x1) * b + c * a) / m;
                    double y = (c * b - (a * y1 - b * x1) * a) / m;
                    int sum = line_iter->addIntersection(x, y) + circle.addIntersection(x, y);
                    if (sum == 2) {
                        count++;
                        //cout << x << " " << y << endl;
                    }
                }
                else {
                    double m = -a * a - b * b;
                    double x = ((a * y1 - b * x1) * b + c * a) / m;
                    double y = (c * b - (a * y1 - b * x1) * a) / m;
                    double t = sqrt((r * r - d * d) / (a * a + b * b));
                    int sum = line_iter->addIntersection(x + b * t, y - a * t) + circle.addIntersection(x + b * t, y - a * t);
                    if (sum == 2) {
                        count++;
                        //cout << x+b*t << " " << y-a*t << endl;
                    }
                    sum = line_iter->addIntersection(x - b * t, y + a * t) + circle.addIntersection(x - b * t, y + a * t);
                    if (sum == 2) {
                        count++;
                        //cout << x-b*t << " " << y+a*t << endl;
                    }
                }
            }
            for (circle_iter = Circlelist.begin(); circle_iter != Circlelist.end(); circle_iter++) {
                x2 = circle_iter->x;
                y2 = circle_iter->y;
                double r2 = circle_iter->r;
                double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
                if (d > r + r2 ||  d < fabs(r - r2))
                    continue;
                else {
                    double t = acos((d * d + r * r - r2 * r2) / (2 * d * r));
                    double m = atan2(y2 - y1, x2 - x1);
                    double x = x1 + r * round(cos(m + t)*10000)/10000;
                    double y = y1 + r * round(sin(m + t)*10000)/10000;
                    int sum = circle_iter->addIntersection(x, y) + circle.addIntersection(x, y);
                    if (sum == 2) {
                        count++;
                        //cout << x << " " << y << endl;
                    }
                    x = x1 + r * round(cos(m - t)*10000)/10000;
                    y = y1 + r * round(sin(m - t)*10000)/10000;
                    sum = circle_iter->addIntersection(x, y) + circle.addIntersection(x, y);
                    if (sum == 2) {
                        count++;
                        //cout << x << " " << y << endl;
                    }
                }
            }
            Circlelist.push_back(circle);
        }
    }
    cout << count << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
