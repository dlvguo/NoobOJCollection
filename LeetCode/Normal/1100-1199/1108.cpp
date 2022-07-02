#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string defangIPaddr(string address)
    {
        string res = "";
        for (auto ch : address)
        {
            if (ch == '.')
                res += "[.]";
            else
                res.push_back(ch);
        }
        return res;
};