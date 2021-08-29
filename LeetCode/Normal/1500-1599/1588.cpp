#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        vector<int> asum(arr.size() + 1, 0);
        asum[1] = arr[0];
        for (int i = 1; i <= arr.size(); i++)
        {
            asum[i] = arr[i - 1] + asum[i - 1];
        }
        int ans = asum.back();
        for (int len = 3; len <= arr.size(); len += 2)
        {
            for (int i = len - 1; i < arr.size(); i++)
            {
                ans += asum[i + 1] - asum[i + 1 - len];
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 4, 2, 5, 3};
    Solution s;
    cout << s.sumOddLengthSubarrays(arr);
}