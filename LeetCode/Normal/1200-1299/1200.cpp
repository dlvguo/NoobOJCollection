#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int _min = abs(arr[1] - arr[0]);
        res.push_back({arr[0], arr[1]});
        for (int i = 2; i < arr.size(); i++)
        {
            int num = abs(arr[i] - arr[i - 1]);
            if (num == _min)
            {
                res.push_back({arr[i - 1], arr[i]});
            }
            else if (num < _min)
            {
                res.clear();
                res.push_back({arr[i - 1], arr[i]});
                _min=num;
            }
        }
        return res;
    }
};