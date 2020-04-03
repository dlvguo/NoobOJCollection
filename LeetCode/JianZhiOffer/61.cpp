#include <bits/stdc++.h>
using namespace std;

bool isStraight(vector<int> &nums)
{
    int zeroCount = 0;
    int index = 0;
    //不一定顺序，如果题目未告诉顺序请不要主观代入
    sort(nums.begin(), nums.end());
    while (index < nums.size() && nums[index] == 0)
    {
        zeroCount++;
        index++;
    }
    for (int i = index + 1; i < nums.size(); i++)
    {
        int num = nums[i] - nums[i - 1] - 1;
        //考虑前后想等问题
        if (zeroCount < num || num == -1)
            return false;
        zeroCount -= num;
    }
    return true;
}