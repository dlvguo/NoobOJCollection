#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //并查集集合
    int find(vector<int> &set, int x)
    {
        return set[x] == -1 ? x : set[x] = find(set, set[x]);
    }

    bool unite(vector<int> &set, int a, int b)
    {
        const int fa = find(set, a);
        const int fb = find(set, b);
        if (fa == fb)
            return false;
        set[fa] = fb;
        return true;
    }

    int removeStones(vector<vector<int>> &stones)
    {
        unordered_map<int, vector<int>> row;
        unordered_map<int, vector<int>> col;
        const int n = stones.size();
        for (int i = 0; i < n; ++i)
        {
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        vector<int> set(n, -1);
        int count = 0;
        for (const auto &[k, v] : row)
        {
            const int t = v[0];
            const int m = v.size();
            for (int i = 1; i < m; ++i)
                if (unite(set, t, v[i]))
                    ++count;
        }
        for (const auto &[k, v] : col)
        {
            const int t = v[0];
            const int m = v.size();
            for (int i = 1; i < m; ++i)
                if (unite(set, t, v[i]))
                    ++count;
        }
        return count;
    }
};
