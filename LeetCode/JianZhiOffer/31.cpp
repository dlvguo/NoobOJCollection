#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> stack;
        int pushIndex = 0, popIndex = 0;
        //模拟进栈就好了
        while (pushIndex < pushed.size() && popIndex < popped.size())
        {
            if (stack.empty())
            {
                stack.push(pushed[pushIndex++]);
            }
            if (stack.top() == popped[popIndex])
            {
                stack.pop();
                popIndex++;
            }
            else
            {
                stack.push(pushed[pushIndex++]);
            }
        }
        while (!stack.empty() && popIndex < popped.size() && stack.top() == popped[popIndex])
        {
            stack.pop();
            popIndex++;
        }
        return pushIndex==popIndex;
    }
};