#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumSwitchingTimes(vector<vector<int>> &source, vector<vector<int>> &target)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < source.size(); i++)
        {
            for (int j = 0; j < source[0].size(); i++)
            {
                umap[source[i][j]]++;
            }
        }
        int ans = 0;

        for (int i = 0; i < target.size(); i++)
        {
            for (int j = 0; j < target[0].size(); i++)
            {
                if (umap.find(target[i][j]) != umap.end())
                {
                    if (umap[target[i][j]])
                    {
                        umap[target[i][j]]--;
                    }
                    else
                    {
                        ans++;
                    }
                }
                else
                    ans++;
            }
        }

        return ans;
    }
};
