#include <bits/stdc++.h>
using namespace std;
class UnionFind
{
public:
    UnionFind(int n)
    {
        parent = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    void uni(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
        {
            if (rank[rootx] > rank[rooty])
            {
                parent[rooty] = rootx;
            }
            else if (rank[rootx] < rank[rooty])
            {
                parent[rootx] = rooty;
            }
            else
            {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution
{
public:
    int largestComponentSize(vector<int> &nums)
    {
        int m = *max_element(nums.begin(), nums.end());
        UnionFind uf(m + 1);
        for (int num : nums)
        {
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    uf.uni(num, i);
                    uf.uni(num, num / i);
                }
            }
        }
        vector<int> counts(m + 1);
        int ans = 0;
        for (int num : nums)
        {
            int root = uf.find(num);
            counts[root]++;
            ans = max(ans, counts[root]);
        }
        return ans;
    }
};
