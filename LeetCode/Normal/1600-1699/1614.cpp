#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        stack<char> st;
        int _max = 0;
        for (auto ch : s)
        {
            if (ch == ')')
            {
                st.pop();
            }
            if (ch == '(')
            {
                st.push('(');
                if (_max < st.size())
                    _max = st.size();
            }
        }
        return _max;
    }
};