#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> stk;
    stack<int> minStk;

public:
    MinStack()
    {
    }

    void push(int x)
    {
        if (minStk.empty() || x <= minStk.top())
        {
            minStk.push(x);
        }

        stk.push(x);
    }

    void pop()
    {
        if (!stk.empty() && stk.top() == minStk.top())
        {
            minStk.pop();
        }

        if (!stk.empty())
            stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return minStk.top();
    }
};
