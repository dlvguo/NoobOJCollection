#include <bits/stdc++.h>
using namespace std;
// 并查集模版
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
            // 按秩合并
            if (rank[rootx] < rank[rooty])
            {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty])
                rank[rootx] += 1;
        }
    }

    bool isSame(int x, int y)
    {
        return find(x) == find(y);
    }
};

struct Edge
{
    int start; // 顶点1
    int end;   // 顶点2
    int len;   // 权值
};
class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<Edge> edges;

        // 生成边
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 下邻接点
                if (i + 1 < n)
                {
                    edges.push_back({i * n + j, (i + 1) * n + j, max(grid[i][j], grid[i + 1][j])});
                }
                // 右邻接点
                if (j + 1 < n)
                {
                    edges.push_back({i * n + j, i * n + j + 1, max(grid[i][j], grid[i][j + 1])});
                }
            }
        }

        // 排序
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a.len < b.len;
        });

        // 依次遍历
        Djset ds(n * n);
        for (const auto &e : edges)
        {
            ds.merge(e.start, e.end);
            if (ds.isSame(0, n * n - 1))
                return e.len;
        }
        return 0;
    }
};