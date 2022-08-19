#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i];
            res ^= i;
        }
        return res ^= nums.size();
    }
};

// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {
//         int i = 0;
//         while (i < nums.size())
//         {
//             if (nums[i] == i || nums[i] == nums.size())
//                 i++;
//             else
//             {
//                 swap(nums[i], nums[nums[i]]);
//             }
//         }
//         for (int i = 0; i < nums.size(); i++)
//             if (nums[i] != i)
//                 return i;
//         return nums.size();
//     }
// };