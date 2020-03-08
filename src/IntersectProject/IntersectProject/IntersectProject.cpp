// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

class Line
{
private:
    map<float, float> intersections;
    map<float, float>::iterator sec_iter;

public:
    float a;
    float b;
    float c;

    Line(float a, float b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    int addIntersection(float x, float y) {
        if (b == 0)
            sec_iter = intersections.find(y);
        else
            sec_iter = intersections.find(x);

        if (sec_iter != intersections.end()) {
            return 0;
        }
        else {
            intersections.insert(pair<float, float>(x, y));
            return 1;
        }
    }
    /*bool isPara(Line line2) {
        if (a * line2.b == b * line2.a) {
            return true;
        }
        return false;
    }*/
};

int main()
{
    list<Line> Linelist;
    list<Line>::iterator line_iter;

    int n, i, j, count;
    float x1, y1, x2, y2;
    float a, b, c;
    string type;

    cin >> n;
    count = 0;
    for (i = 0; i < n; i++) {
        cin >> type >> x1 >> y1 >> x2 >> y2;
        a = y2 - y1;
        b = x1 - x2;
        c = x2 * y1 - x1 * y2;
        Line line(a, b, c);
        for (line_iter = Linelist.begin(); line_iter != Linelist.end(); line_iter++) {
            float a2 = line_iter->a;
            float b2 = line_iter->b;
            float c2 = line_iter->c;
            if (a * b2 == a2 * b) {
                continue;
            }
            else {
                float m = a * b2 - a2 * b;
                float x = (c2 * b - c * b2) / m;
                float y = (c2 * a - c * a2) / m;
                int sum = line_iter->addIntersection(x, y) + line.addIntersection(x, y);
                if (sum == 2) count++;
            }
        }
        Linelist.push_back(line);
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
