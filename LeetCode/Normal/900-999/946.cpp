#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int i = 0;
        stack<int> s;
        for (int j = 0; j < pushed.size(); j++)
        {
            while (s.size() && i < popped.size() && s.top() == popped[i])
            {
                i++;
                s.pop();
            }
            s.push(pushed[j]);
        }
        while (s.size() && i < popped.size() && s.top() == popped[i])
        {
            i++;
            s.pop();
        }
        return s.empty();
    }
};