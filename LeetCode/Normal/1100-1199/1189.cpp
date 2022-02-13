#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int nums[5] = {0};
        int sub[5] = {1, 1, 2, 2, 1};
        for (auto ch : text)
        {
            if (ch == 'b')
                nums[0]++;
            else if (ch == 'a')
                nums[1]++;
            else if (ch == 'l')
                nums[2]++;
            else if (ch == 'o')
                nums[3]++;
            else if (ch == 'n')
                nums[4]++;
        }
        int res = 0;
        while (1)
        {

            for (int i = 0; i < 5; i++)
            {
                if (nums[i] >= sub[i])
                {
                    nums[i] -= sub[i];
                }
                else
                    return res;
            }
            res++;
        }
        return res;
    }
};