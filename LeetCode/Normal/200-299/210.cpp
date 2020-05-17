#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        for (auto &p : prerequisites)
        {
            graph[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        stack<int> stk;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                stk.push(i);
        }
        stack<int> order;
        while (!stk.empty())
        {
            int c = stk.top();
            stk.pop();
            order.push(c);
            for (auto &pre : graph[c])
            {
                indegree[pre]--;
                if (indegree[pre] == 0)
                {
                    stk.push(pre);
                }
            }
        }
        vector<int> res;
        if (order.size() < numCourses)
            return res;
        while (!order.empty())
        {
            res.push_back(order.top());
            order.pop();
        }
        return res;
    }
};