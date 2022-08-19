#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, vector<int> &B)
{
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
            // auto it=
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

int main()
{
    vector<int> A = {0}, B = {1};
    cout << solution(A, B);
}