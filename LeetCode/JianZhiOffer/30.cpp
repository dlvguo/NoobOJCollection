#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    vector<int> minStack;
    vector<int> stack;

    MinStack()
    {
    }

    void push(int x)
    {
        stack.push_back(x);
        if (minStack.empty() || minStack.back() >= x)
            minStack.push_back(x);
    }

    void pop()
    {
        if (stack.empty())
            return;
        int top = stack.back();
        stack.pop_back();
        if (top == minStack.back())
            minStack.pop_back();
    }

    int top()
    {
        if (stack.empty())
            return -1;
        return stack.back();
    }

    int min()
    {
        if (minStack.empty())
            return -1;
        return minStack.back();
    }
};
