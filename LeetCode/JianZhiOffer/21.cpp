#include <bits/stdc++.h>
using namespace std;

vector<int> exchange(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        while (low < high && nums[high] % 2 == 0)
        {
            high--;
        }
        while (low < high && nums[low] % 2)
        {
            low++;
        }
        if (low < high)
        {
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }
    return nums;
}