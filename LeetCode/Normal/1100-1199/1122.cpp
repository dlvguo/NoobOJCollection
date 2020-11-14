#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> sets(1001, 0);
        for (int i = 0; i < arr1.size(); i++)
        {
            sets[arr1[i]]++;
        }
        vector<int> nums;
        for (int i = 0; i < arr2.size(); i++)
        {
            while (sets[arr2[i]])
            {
                nums.push_back(arr2[i]);
                sets[arr2[i]]--;
            }
        }
        for (int i = 0; i < 1001; i++)
        {
            while (sets[i])
            {
                nums.push_back(i);
                sets[i]--;
            }
        }
        return nums;
    }
};