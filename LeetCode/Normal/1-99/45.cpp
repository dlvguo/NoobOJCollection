#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        int n = nums.size();
        int sum = 0;
        int end = 0;  //能跳到的最远距离
        int max1 = 0; //下一步可以跳到的最远距离
        for (int i = 0; i < n - 1; i++)
        {
            max1 = max(max1, i + nums[i]);
            //更新当前点
            if (i == end)
            {
                end = max1;
                sum++;
            }
        }
        return sum;
    }
};