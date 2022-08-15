#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> subSort(vector<int> &array)
    {
        if (array.size() < 2)
            return {-1, -1};
        map<int, int> _map;
        int l = -1, r = -1;
        for (int i = 0; i < array.size(); i++)
        {
            auto ite = _map.upper_bound(array[i]);
            if (ite != _map.end())
            {
                if (l == -1 || ite->second < l)
                {
                    l = ite->second;
                }
                r = i;
            }
            if (_map.find(array[i]) == _map.end())
                _map[array[i]] = i;
        }
        return {l, r};
    }
};