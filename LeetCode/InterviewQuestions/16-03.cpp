#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    const double E = 1e-6;
    bool inLine(double x, double s, double e)
    { // 判断x是否在s->e或e->s之间
        if (abs(x - s) < E || abs(x - e) < E)
            return true;
        return (x - s > 0 && e - x > 0) || (x - e > 0 && s - x > 0);
    }

public:
    vector<double> intersection(vector<int> &start1, vector<int> &end1, vector<int> &start2, vector<int> &end2)
    {
        int x1 = start1[0], y1 = start1[1], x2 = end1[0], y2 = end1[1];
        int x3 = start2[0], y3 = start2[1], x4 = end2[0], y4 = end2[1];
        int a11 = y2 - y1, a12 = x1 - x2, b1 = x1 * y2 - x2 * y1;
        int a21 = y4 - y3, a22 = x3 - x4, b2 = x3 * y4 - x4 * y3;
        int D = a11 * a22 - a12 * a21, D1 = b1 * a22 - a12 * b2, D2 = a11 * b2 - b1 * a21;
        if (D == 0 && D1 == 0)
        { //平行且共线
            if (min(x3, x4) > max(x1, x2) || min(x1, x2) > max(x3, x4))
                return {}; //分离
            if (min(y3, y4) > max(y1, y2) || min(y1, y2) > max(y3, y4))
                return {}; //分离
            vector<vector<int>> v{{x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}};
            sort(v.begin(), v.end());
            return {(double)v[1][0], (double)v[1][1]}; //取第二小的即所求交点
        }
        if (D != 0)
        {                                                    //不平行
            double x0 = D1 / (double)D, y0 = D2 / (double)D; //交点
            if (inLine(x0, x1, x2) && inLine(x0, x3, x4) && inLine(y0, y1, y2) && inLine(y0, y3, y4))
                return {x0, y0};
        }
        return {};
    }
};