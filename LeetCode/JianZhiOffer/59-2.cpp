#include <bits/stdc++.h>
using namespace std;

class MaxQueue
{
public:
    queue<int> q;
    deque<int> dq;

    MaxQueue()
    {
    }

    int max_value()
    {
        return dq.empty() ? -1 : dq.front();
    }

    void push_back(int value)
    {
        q.push(value);
        while (!dq.empty() && dq.back() < value)
        {
            dq.pop_back();
        }
        dq.push_back(value);
    }

    int pop_front()
    {
        if (q.empty())
            return -1;
        int val = q.front();
        q.pop();
        if (val == dq.front())
            dq.pop_front();
        return val;
    }
};
