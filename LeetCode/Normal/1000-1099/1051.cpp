#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> res;
        for (int i = 0; i < heights.size(); i++)
        {
            res.push_back(heights[i]);
        }
        sort(res.begin(),res.end());
        int ans=0;
        for (int i = 0; i < heights.size(); i++)
        {
           if(res[i]!=heights[i])
            ans++;
        }
        return ans;
    }
};