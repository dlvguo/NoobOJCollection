#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<int, int> _map;
    vector<pair<int, int>> ns;

    void _qsort(int l, int r, int k)
    {
        int ol = l, oR = r;
        // 获取最左边的
        pair<int, int> temp = ns[l];

        while (l < r)
        {

            while (l < r && ns[r].second <= temp.second)
                r--;
            swap(ns[l], ns[r]);
            while (l < r && ns[l].second >= temp.second)
                l++;
            swap(ns[l], ns[r]);
        }
        ns[l] = temp;
        //确定下标
        if (l + 1 == k)
            return;
        else if (l + 1 >= k)
            _qsort(ol, l - 1, k);
        else
            _qsort(l + 1, oR, k);
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            _map[nums[i]]++;
        }
        for (auto _m : _map)
        {
            ns.push_back(_m);
        }
        _qsort(0, ns.size() - 1, k);
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(ns[i].first);
        }
        return res;
    }
};
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution s;
    s.topKFrequent(nums, 2);
}