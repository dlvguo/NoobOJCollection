#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;

    MedianFinder() {}

    void addNum(int num)
    {
        if (queMin.empty() || num <= queMin.top())
        {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size())
            {
                queMax.push(queMin.top());
                queMin.pop();
            }
        }
        else
        {
            queMax.push(num);
            if (queMax.size() > queMin.size())
            {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian()
    {
        if (queMin.size() > queMax.size())
        {
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};
