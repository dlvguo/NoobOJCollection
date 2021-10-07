#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long long fst = INT64_MIN, sec = INT64_MIN, third = INT64_MIN;
        bool tag = false;
        for (auto num : nums)
        {
            if (num > fst)
            {
                third = sec;
                sec = fst;
                fst = num;
            }
            else if (num < fst)
            {
                if (num > sec)
                {
                    third = sec;
                    sec = num;
                }
                else if (num < sec)
                {
                    if (num > third)
                        third = num;
                }
            }
        }
        return third == INT64_MIN ? fst : third;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 2, 1};
    s.thirdMax(nums);
}