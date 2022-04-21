#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> outDe(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto query : prerequisites)
        {
            outDe[query[0]]++;
            graph[query[1]].push_back(query[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (!outDe[i])
                q.push(i);
        vector<int> res;
        while (q.size())
        {
            int num = q.size();
            while (num--)
            {
                int outNode = q.front();
                q.pop();
                res.push_back(outNode);
                for (int i = 0; i < graph[outNode].size(); i++)
                {
                    int node = graph[outNode][i];
                    outDe[node]--;
                    if (!outDe[node])
                        q.push(node);
                }
            }
        }
        //注意考虑可以的情况
        if (res.size() == numCourses)
            return res;
        return {};
    }
};