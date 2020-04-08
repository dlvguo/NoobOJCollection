#include <bits/stdc++.h>
using namespace std;

class CQueue
{
public:
    stack<int> s1, s2;
    CQueue()
    {
    }

    void appendTail(int value)
    {
        s1.push(value);
    }

    int deleteHead()
    {
        int temp;
        if (s1.empty() && s2.empty())
            temp = -1;
        else if (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            temp = s2.top();
            s2.pop();
        }
        return temp;
    }
};
