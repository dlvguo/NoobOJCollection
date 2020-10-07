#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1, temp = 0;
        while (temp <= right)
        {
            if (nums[temp] == 0)
            {
                int t = nums[left];
                nums[left++] = nums[temp];
                nums[temp++] = t;
            }
            else if (nums[temp] == 1)
            {
                temp++;
            }
            else
            {
                int t = nums[right];
                nums[right--] = nums[temp];
                nums[temp] = t;
            }
        }
    }
};

int main()
{
    Solution s = Solution();
    vector<int> v = {2, 0, 1};
    s.sortColors(v);
}