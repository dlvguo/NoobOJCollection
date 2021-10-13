#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> res;
        for (int i = 1; i <= n; i++)
        {
            string str = "";
            bool tag = 0;
            if (i % 3 == 0)
            {
                str += "Fizz";
                tag = 1;
            }
            if (i % 5 == 0)
            {
                str += "Buzz";
                tag = 1;
            }
            if (!tag)
                str += to_string(i);
            res.push_back(str);
        }
        return res;
    }
};