#include <bits/stdc++.h>
using namespace std;

/**
 * 思路：根据拓扑排序的思想，因为是有向图，每次把度为1的放入队列，0不放进去，因为N-1条边，能保证每次做外部的节点只有度为1
 * degree表示存放节点的度，节点出去将度减去
 * people表示该节点的人数，每次更新点要把原来的人放入新的点，注意统计燃油的时候/5
 **/
int solution(vector<int> &A, vector<int> &B)
{
    // 构造无向图
    unordered_map<int, unordered_set<int>> graph;
    vector<int> degree(A.size() + 1, 0);
    vector<int> people(A.size() + 1, 1);
    int num = 0;
    int N = A.size();
    for (int i = 0; i < N; i++)
    {
        int a = A[i], b = B[i];
        degree[a]++;
        degree[b]++;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (degree[i] == 1)
        {
            q.push(i);
        }
    }

    int res = 0;

    while (q.size())
    {
        int count = q.size();
        while (count--)
        {
            int node = q.front();
            q.pop();
            //加上燃油
            res += ((4 + people[node]) / 5);
            //找到对应的值
            int pnode = *graph[node].begin();
            degree[pnode]--;
            graph[pnode].erase(node);
            // 注意0不放
            if (degree[pnode] == 1 && pnode)
                q.push(pnode);
            //人要加过来
            people[pnode] += people[node];
        }
    }
    return res;
}
