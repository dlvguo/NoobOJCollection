#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long sum = 0;
        int i = 0;

        for (i = 0; i < chalk.size(); i++)
        {
            sum += chalk[i];
        }
        k = k - k / sum * sum;
        i = 0;
        while (k >= chalk[i])
        {
            k -= chalk[i];
        }
        return i;
    }
};