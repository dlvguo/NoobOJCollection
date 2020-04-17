#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = 1;
        //从倒二个往前推
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] >= n) //说明可以跨到
            {
                n = 1;
            }
            else //跨不到说明n+1
            {
                n++;
            }
        }
        return n == 1;
    }
};

//8ms版本
bool canJump(vector<int> &nums)
{
    int can_reach = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > can_reach)
            return false;
        can_reach = max(can_reach, i + nums[i]);
    }
    return true;
}