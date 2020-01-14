#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> vv;
    //首先排序一波
    sort(nums.begin(), nums.end());
    int len = nums.size(), low, high, temp;
    //nums[i]若>0说明 无需要再比较不可能出现数字
    //注意判断重复问题
    for (int i = 0; i < len - 2 && nums[i] <= 0; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        temp = nums[i];
        low = i + 1;
        high = len - 1;
        while (low < high)
        {
            if (nums[low] + nums[high] + temp == 0)
            {
                vv.push_back({temp, nums[low], nums[high]});
                low++;
                high--;
                while (low < high && nums[low] == nums[low - 1])
                {
                    low++;
                }
                while (low < high && nums[high] == nums[high + 1])
                {
                    high--;
                }
            }
            else if (temp + nums[low] + nums[high] < 0)
            {
                low++;
            }
            else
                high--;
        }
    }
    return vv;
}

int main()
{
}