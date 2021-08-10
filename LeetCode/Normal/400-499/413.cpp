#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fig(int n)
    {
        if (n < 3)
            return 0;
        return (n - 1) * (n - 2) / 2;
    }
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;
        int l = 0, r = 0, count, ans = 0;

        while (l < nums.size() - 2)
        {
            if (l == r)
            {
                r++;
                count = 2;
            }
            int diff = nums[r] - nums[l];
            while (r + 1 < nums.size() && nums[r + 1] - nums[r] == diff)
            {
                count++;
                r++;
            }
            ans += fig(count);
            l = r;
        }
        return ans;
    }
};

int main()
{
}