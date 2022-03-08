#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        // 代表此下标后面最近的一个柱子下标
        vector<int> rightindexs(s.size(), 0);
        // 代表左边最近的一个柱子下标
        vector<int> leftindexs(s.size(), 0);
        unordered_map<int, int> zznum;
        int pre = -1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '|')
                pre = i;
            rightindexs[i] = pre;
        }
        int res = 1;
        zznum[-1] = 0;
        pre = -1;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '|')
            {
                pre = i;
                zznum[pre] = res++;
            }
            leftindexs[i] = pre;
        }

        vector<int> ans;
        for (auto q : queries)
        {
            int l = rightindexs[q[0]], r = leftindexs[q[1]];
            // 找不到间隔的柱子
            if (l >= r || l == -1)
            {
                ans.push_back(0);
                continue;
            }
            else
            {
                ans.push_back(r - l - zznum[r] + zznum[l]);
            }
        }
        return ans;
    }
};