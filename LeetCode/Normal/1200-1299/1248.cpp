#include <bits/stdc++.h>
using namespace std;

//尺取法
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int left = 0, right = 0, oddNum = 0, ans = 0;
        while (right <= nums.size() - 1)
        {
            //计算奇数
            if (nums[right++] % 2)
            {
                oddNum++;
                if (oddNum == k)
                {
                    int count = 1;
                    for (int i = right; i < nums.size(); i++)
                    {
                        if (nums[i] % 2 == 0)
                            count++;
                        else
                            break;
                    }

                    while (left < right && oddNum == k)
                    {
                        ans += count;
                        if (nums[left] % 2)
                            oddNum--;
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{

    Solution s1;
    vector<int> v{45627, 50891, 94884, 11286, 35337, 46414, 62029, 20247, 72789, 89158, 54203, 79628, 25920, 16832, 47469, 80909};
    s1.numberOfSubarrays(v, 1);
}