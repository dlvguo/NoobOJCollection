#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int i = 0;
        string res;
        while ((i < num.size()) && (k > 0))
        {
            int minIndex = i;
            int j = i + 1;
            while (j < i + k + 1)
            {
                if (num[j] < num[minIndex])
                {
                    minIndex = j;
                }
                j++;
            }
            if ((minIndex < num.size()) && ((res.size() != 0) || (num[minIndex] != '0')))
            {
                res += string(1, num[minIndex]);
            }
            k -= (minIndex - i);
            i = minIndex + 1;
        }
        for (int m = i; m < num.size(); m++)
        {
            if ((res.size() != 0) || (num[m] != '0'))
            {
                res += string(1, num[m]);
            }
        }
        return (res.size() == 0) ? "0" : res;
    }
};