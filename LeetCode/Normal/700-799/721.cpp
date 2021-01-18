#include <bits/stdc++.h>
using namespace std;

class Djset
{
public:
    vector<int> parent; // 记录节点的根
    vector<int> rank;   // 记录根节点的深度（用于优化）
    Djset(int n) : parent(vector<int>(n)), rank(vector<int>(n))
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        // 压缩方式：直接指向根节点
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
        {
            if (rank[rootx] < rank[rooty])
            {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty])
                rank[rootx] += 1;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &acc)
    {
        vector<vector<string>> res;
        // 作用：存储每个邮箱属于哪个账户
        // 格式：
        unordered_map<string, int> um;
        int n = acc.size();
        Djset ds(n);
        for (int i = 0; i < n; i++)
        {
            int m = acc[i].size();
            for (int j = 1; j < m; j++)
            {
                string s = acc[i][j];
                if (um.find(s) == um.end())
                {
                    um[s] = i;
                }
                else
                {
                    ds.merge(i, um[s]);
                }
            }
        }

        unordered_map<int, vector<string>> umv;
        for (auto &[k, v] : um)
            umv[ds.find(v)].emplace_back(k);
        for (auto &[k, v] : umv)
        {
            sort(v.begin(), v.end());
            vector<string> tmp(1, acc[k][0]);
            tmp.insert(tmp.end(), v.begin(), v.end());
            res.emplace_back(tmp);
        }

        return res;
    }
};
