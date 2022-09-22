#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        unordered_map<int, int> index;
        for (int i = 0; i < pieces.size(); i++)
        {
            index[pieces[i][0]] = i;
        }
        for (int i = 0; i < arr.size();)
        {
            auto it = index.find(arr[i]);
            if (it == index.end())
            {
                return false;
            }
            for (int x : pieces[it->second])
            {
                if (arr[i++] != x)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
