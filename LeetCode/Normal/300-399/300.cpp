#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //用二分法维护一个最长序列 
    void binSelect(vector<int> &nums, int n)
    {
        int mid, low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = (low + high)/2;
            if (nums[mid] < n)//因为强递增不能够有相等 于是else包括>= 如果非强递增else只包括>
                low = mid + 1;
            else
            {
                high=mid;
            }
        }
        nums[low]=n;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> astNums;
        if (nums.size())
        {
            astNums.push_back(nums[0]);
            for (int i = 1; i < nums.size(); i++)
            {
                if (astNums.back() < nums[i])
                    astNums.push_back(nums[i]);
                else
                    binSelect(astNums, nums[i]);
            }
        }
        return astNums.size();
    }
};

int main()
{
    vector<int> v = {4, 10,4,3,8,9};
    Solution s1;
    cout << s1.lengthOfLIS(v) << endl;
    system("pause");
}