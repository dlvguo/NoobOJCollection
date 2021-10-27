#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums2.size(); i++)
        {
            int bigger = -1;
            for (int j = i + 1; j < nums2.size(); j++)
            {
                if (nums2[j] > nums2[i])
                {
                    bigger = nums2[j];
                    break;
                }
            }
            umap[nums2[i]] = bigger;
        }
        vector<int> res;
        for (auto num : nums1)
        {
            res.push_back(umap[num]);
        }
        return res;
    }
};