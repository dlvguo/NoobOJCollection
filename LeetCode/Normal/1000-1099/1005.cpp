#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     int largestSumAfterKNegations(vector<int> &nums, int k)
//     {
//         if (nums.size() == 1)
//             return k % 2 ? -nums[0] : nums[0];
//         sort(nums.begin(), nums.end());
//         //先看有没有负数
//         int i = 0;
//         int res = 0;
//         for (i = 0; i < nums.size() && nums[i] < 0&&k; i++)
//         {
//             nums[i] = -nums[i];
//             k--;
//             res += nums[i];
//         }
//         //说明全是负数
//         if (i == nums.size())
//         {
//             return k % 2 ? res - 2*nums.back() : res;
//         }
//         //开始统计0或者负数
//         if (nums[i] && k % 2)
//         {
//             if (i!=0&&nums[i - 1] < nums[i])
//                 res -= 2*nums[i - 1];
//             else
//             {
//                 res -= nums[i];
//                 i++;
//             }
//         }

//         for (; i < nums.size(); i++)
//         {
//             res += nums[i];
//         }
//         return res;
//     }
// };

class Solution
{
public:
    static bool cmp(const int a, const int b)
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        if (nums.size() == 1)
            return k % 2 ? -nums[0] : nums[0];
        sort(nums.begin(), nums.end(), cmp);
        //先看有没有负数
        int i = 0;
        int res = 0;
        for (i = 0; i < nums.size(); i++)
        {
            if (k && nums[i] < 0)
            {
                k--;
                nums[i] = -nums[i];
            }
            res += nums[i];
        }
        return k % 2 ? res - 2 * nums.back() : res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-8, 3, -5, -3, -5, -2};
    int k = 6;
    s.largestSumAfterKNegations(v, k);
}