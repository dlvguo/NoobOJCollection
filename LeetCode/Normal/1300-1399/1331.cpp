#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }

        int num = 1;

        for (auto m : mp)
        {
            for (int i = 0; i < m.second.size(); i++)
                arr[m.second[i]] = num;
            num++;
        }
        return arr;
    }
};