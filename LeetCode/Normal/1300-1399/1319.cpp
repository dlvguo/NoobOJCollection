#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int SearchFather(vector<int> &sets, int x)
    {
        if (sets[x] == -1)
            return x;
        return sets[x] = SearchFather(sets, sets[x]);
    }

    void Union(int a, int b, vector<int> &sets)
    {
        int f_a = SearchFather(sets, a), f_b = SearchFather(sets, b);
        if (f_a != -1 && f_a == f_b)
            return;
        sets[f_a] = b;
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if(connections.size()<n-1)
            return -1;
        vector<int> sets(n, -1);
        for (int i = 0; i < connections.size(); i++)
        {
            Union(connections[i][0], connections[i][1], sets);
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (sets[i] == -1)
                ans++;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    Solution s;
    s.makeConnected(6, connections);
}