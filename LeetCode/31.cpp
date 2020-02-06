#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int i = 0, j = nums.size() - 1;
    for (i = nums.size() - 1; i && nums[i - 1] >= nums[i]; --i);
    //避免只有1的情况
    if (i)
    {
        for (j = nums.size() - 1; i < j && nums[i - 1] >= nums[j]; --j)
            ;
        swap(nums[i - 1], nums[j]);
    }
    reverse(nums.begin() + (i - 1 == j ? 0 : i), nums.end());
}

int main()
{
    vector<int> v = {4, 2, 0, 2, 3, 2, 0};
    nextPermutation(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    system("pause");
    return 0;
}