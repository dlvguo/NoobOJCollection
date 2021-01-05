#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //全局变量2个
    vector<double> res;
    bool Nofand;
    void dfs(unordered_map<string, vector<pair<string, double>>> &g, unordered_map<string, int> &visit, string val, const string &target, const double &path)
    {
        //如果节点已经相连接，那没 必要再dfs搜索了，直接返回
        if (Nofand == false)
            return;
        if (val == target)
        {
            Nofand = false;
            res.push_back(path);
            return;
        }
        for (int j = 0; j < g[val].size(); ++j)
        {
            //检查与val相连接的点，是否已经访问过了。没访问过继续dfs
            if (visit[g[val][j].first] == 0)
            {
                visit[g[val][j].first] = 1;
                dfs(g, visit, g[val][j].first, target, path * g[val][j].second);
                visit[g[val][j].first] = 0;
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        //string - string(double)  a连接b(b带上权值)
        unordered_map<string, vector<pair<string, double>>> g;
        unordered_map<string, int> visit;
        //构建无向图，a-b的value是3 的话 ，b-a是3的倒数
        for (int i = 0; i < equations.size(); ++i)
        {
            g[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            g[equations[i][1]].push_back(make_pair(equations[i][0], 1.0 / values[i]));
        }
        //遍历queries，对每一组进行dfs计算结果。
        //如果相连接，就把 路径上的权值相乘就是结果
        for (int i = 0; i < queries.size(); ++i)
        {
            //如果queries[0]是不存在的，直接出结果：-1
            if (g.find(queries[i][0]) == g.end())
            {
                res.push_back(-1.0);
                continue;
            }
            //设置一个全局变量，如果进行dfs后，queries[0]到不了queries[1]，Nofind = true;
            Nofand = true;
            visit[queries[i][0]] = 1;
            dfs(g, visit, queries[i][0], queries[i][1], 1);
            visit[queries[i][0]] = 0;

            if (Nofand)
                res.push_back(-1.0);
        }
        return res;
    }
};