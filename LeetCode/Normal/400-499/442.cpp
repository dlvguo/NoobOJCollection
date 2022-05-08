#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        int l = 0;
        while (l < nums.size())
        {
            // 1放到0的位置
            int num = nums[l];
            // 说明这里换过位置
            if (num < 1)
                l++;
            else
            {
                //说明就在原地
                if (num == l + 1)
                {
                    l++;
                }
                else
                {
                    // 对应的那个数
                    int pnum = nums[num - 1];
                    if (pnum == num)
                    {
                        res.push_back(num);
                        nums[l++] = 0;
                    }
                    else
                    {
                        swap(nums[l],nums[num-1]);
                    }
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution s;
    s.findDuplicates(nums);
}