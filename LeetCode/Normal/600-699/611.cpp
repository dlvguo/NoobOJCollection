#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        int len = nums.size();

        for (int i = 0; i < len - 2; i++)
        {
            for (int j = i + 1; j < len - 1; j++)
            {
                int n = nums[i] + nums[j]; //找到小于n的最大数
                int l = j + 1, r = len - 1;
                while (l < r)
                {
                    int mid = (l + r + 1) / 2;
                    if (nums[mid] < n)
                        l = mid;
                    else
                    {
                        r = mid - 1;
                    }
                }
                if (l < nums.size() && nums[l] < n)
                {
                    count += l - j;
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {1};
}