#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
    int _temp = 0;
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),2));
        unordered_map<int, int> umap;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                int k = arr[i] - arr[j];
                if(k>=arr[j])
                    break;
                if (umap.find(k) != umap.end())
                {
                    dp[i][j] = max(dp[i][j], dp[j][umap[k]] + 1);
                    _temp = max(dp[i][j], _temp);
                }
            }
            umap[arr[i]]=i;
        }
        return _temp;
    }
};