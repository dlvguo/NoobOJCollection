#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> nums(n, 0), index(3, 0);
        nums[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int a = nums[index[0]] * 2, b = nums[index[1]] * 3, c = nums[index[2]] * 5;
            int next = min(a, min(b, c));
            if (next == a)
                index[0]++;
            if (next == b)
                index[1]++;
            if (next == c)
                index[2]++;
            nums[i] = next;
        }
        return nums.back();
    }
};

int main()
{
    Solution s;
    s.nthUglyNumber(10);
}