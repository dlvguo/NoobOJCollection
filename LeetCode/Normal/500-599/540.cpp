#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        int low = 0, right = nums.size() - 1;
        int res = nums[0];
        while (low <= right)
        {
            int mid = (low + right) / 2;
            // 注意mid^1的妙用！ 跟奇偶数放在一起可以快速判断邻近的值
            if (nums[mid] == nums[mid ^ 1])
            {
                low = mid + 1;
            }
            else
            {
                res = nums[mid];
                right = mid - 1;
            }
        }
        return res;
    }
};