#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string printBin(double num)
    {
        string res = "0.";
        while (num)
        {
            num *= 2;
            if (num >= 1)
            {
                res.push_back('1');
                num--;
            }
            else
            {
                res.push_back('0');
            }
            if(res.size()>32)
                return "ERROR";
            /* code */
        }
        return res;
    }
};