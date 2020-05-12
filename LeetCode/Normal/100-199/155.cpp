#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class MinStack
{
public:
    stack<int> s1, s2;
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        s1.push(x);
        //注意一开始可能为空的情况
        if (s2.empty() || x <= s2.top())
            s2.push(x);
    }

    void pop()
    {
        int top = s1.top();
        s1.pop();
        if (s2.top() == top)
            s2.pop();
    }

    int top()
    {
        return s1.top();
    }

    int getMin()
    {
        return s2.top();
    }
};
