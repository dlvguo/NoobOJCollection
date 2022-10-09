#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> idx1(n), idx2(n);
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);
        sort(idx1.begin(), idx1.end(), [&](int i, int j)
             { return nums1[i] < nums1[j]; });
        sort(idx2.begin(), idx2.end(), [&](int i, int j)
             { return nums2[i] < nums2[j]; });

        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i)
        {
            if (nums1[idx1[i]] > nums2[idx2[left]])
            {
                ans[idx2[left]] = nums1[idx1[i]];
                ++left;
            }
            else
            {
                ans[idx2[right]] = nums1[idx1[i]];
                --right;
            }
        }
        return ans;
    }
};
