#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        string str;
        stack<char> st;
        int num = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '-')
                continue;
            if (s[i] >= 'a' && s[i] <= 'z')
                st.push(s[i] - 32);
            else
                st.push(s[i]);
            num++;
            if (num == k)
            {
                num = 0;
                st.push('-');
            }
        }
        if (st.size() && st.top() == '-')
            st.pop();
        while (st.size())
        {
            str.push_back(st.top());
            st.pop();
        }
        return str;
    }
};