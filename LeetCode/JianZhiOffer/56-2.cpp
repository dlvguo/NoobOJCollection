#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        //注意边界问题
        for (int i = 0; i < nums.size() - 2; i += 3)
        {
            if (nums[i] != nums[i + 2])
                return nums[i];
        }
        return nums.back();
    }
};

//还有个思路 一个int 32位，出现3次的必然能被3整除，而一次的位必然不能遍历累加即可