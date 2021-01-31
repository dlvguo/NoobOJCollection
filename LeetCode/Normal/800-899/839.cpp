#include <bits/stdc++.h>
using namespace std;

//并查集 如果相似就联合在一起看 相似就看有没有俩个地方不一样
class Solution
{
public:
    vector<int> sets;
    //检查相似
    bool check(string &a, string &b)
    {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                cnt++;
                if (cnt > 2)
                    return false;
            }
        }
        return cnt <= 2;
    }

    int findAncestor(int x)
    {
        if (sets[x] == -1)
            return x;
        return sets[x] = findAncestor(sets[x]);
    }

    int numSimilarGroups(vector<string> &strs)
    {
        sets.resize(strs.size(), -1);

        for (int i = 0; i < strs.size() - 1; i++)
        {
            for (int j = i + 1; j < strs.size(); j++)
            {
                int fa = findAncestor(i);
                int fb = findAncestor(j);
                if (fa == fb)
                    continue;
                if (check(strs[i], strs[j]))
                {
                    sets[fa] = fb;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < sets.size(); i++)
        {
            if (sets[i] == -1)
                ans++;
        }

        return ans;
    }
};