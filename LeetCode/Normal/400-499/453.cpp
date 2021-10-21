#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //n-1个数加1 等同于1个数减1 于是计算每个数到最小值的数量即可
    int minMoves(vector<int> &nums)
    {
        int minNum = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums)
        {
            res += num - minNum;
        }
        return res;
    }
};