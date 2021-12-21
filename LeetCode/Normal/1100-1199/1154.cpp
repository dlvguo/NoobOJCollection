#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dayOfYear(string date)
    {
        int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
        int month = (date[5] - '0') * 10 + (date[6] - '0');
        int day = (date[8] - '0') * 10 + (date[9] - '0');
        int res = 0;
        int md[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        for (int i = 1; i < 12; i++)
        {
            md[i] += md[i - 1];
        }

        if (month > 2 && (year % 400 == 0 || year % 4 == 0 && year % 100 != 0))
        {
            res++;
        }
        return res + day + md[month - 1];
    }
};