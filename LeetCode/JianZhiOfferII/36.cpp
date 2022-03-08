#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int res = 0;
        stack<int> s;
        for (auto tk : tokens)
        {
            if (tk == "+" || tk == "-" || tk == "/" || tk == "*")
            {
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();
                if (tk == "+")
                {
                    s.push(n1 + n2);
                }
                else if (tk == "-")
                {
                    s.push(n2 - n1);
                }
                else if (tk == "/")
                {
                    s.push(n2 / n1);
                }
                else
                    s.push(n2 * n1);
            }
            else
                s.push(atoi(tk.c_str()));
        }
        return s.top();
    }
};