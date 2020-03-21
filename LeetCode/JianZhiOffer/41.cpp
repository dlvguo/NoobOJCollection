#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int, vector<int>, less<int>> max;
    priority_queue<int, vector<int>, greater<int>> min;
    //俩个堆维护 一个大顶堆和一个小顶堆  大顶堆维护1-n/2 小顶堆维护 n/2-n 每次插入大的
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        max.push(num);
        min.push(max.top());
        max.pop();
        if (max.size() + 1 < min.size())
        {
            max.push(min.top());
            min.pop();
        }
    }

    double findMedian()
    {
        if (max.size() == min.size())
        {
            double k = 1.0 * (max.top() + min.top()) / 2;
            return k;
        }
        return min.top();
    }
};

int main()
{
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    cout << m.findMedian() << endl;
    system("pause");
}
