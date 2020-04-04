#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() == 0)
            return 0;
        //left[i]表示i左边当前点最高 right[i]表示右边点最高
        vector<int> left(height.size(), 0), right(height.size(), 0);
        left[0] = height[0];
        for (int i = 1; i < height.size() - 1; i++)
        {
            left[i] = max(left[i - 1], height[i]);
        }
        right.back() = height.back();
        for (int i = height.size() - 2; i >= 2; i--)
        {
            right[i] = max(height[i], right[i + 1]);
        }
        int water = 0;
        for (int i = 1; i < height.size() - 1; i++)
        {
            //获取左右边点中短的
            int level = min(left[i - 1], right[i + 1]);
            //如果比当前高度多说明可以装水 在槽里
            water += max(0, level - height[i]);
        }
        return water;
    }
};