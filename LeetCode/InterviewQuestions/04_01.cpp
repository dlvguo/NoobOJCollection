#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start, int target)
    {
        if (start == target)
            return true;
        unordered_map<int, vector<int>> map;
        for (vector<int> &vec : graph)
        {
            map[vec[0]].push_back(vec[1]);
        }
        vector<bool> visited(n, false);
        queue<int> queue;
        queue.push(start);
        while (!queue.empty())
        {
            int cur = queue.front();
            queue.pop();
            visited[cur] = true;
            for (int point : map[cur])
            {
                if (point == target)
                    return true;
                else if (visited[point] == false)
                    queue.push(point);
            }
        }
        return false;
    }
};
