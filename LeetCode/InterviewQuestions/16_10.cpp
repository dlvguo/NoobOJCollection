#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAliveYear(vector<int> &birth, vector<int> &death)
    {
        int diff[103] = {0};

        for (int i = 0; i < birth.size(); i++)
        {
            diff[birth[i] - 1899] += 1;
            diff[death[i] - 1898] -= 1;
        }

        int ans = 1, year = birth[0];

        for (int i = 1; i < 102; i++)
        {
            diff[i] += diff[i - 1];
            if (ans < diff[i])
            {
                year = i + 1899;
                ans = diff[i];
            }
        }
        return year;
    }
};