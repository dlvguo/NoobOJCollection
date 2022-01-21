#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        unordered_map<int, vector<int>> idxSameValue;
        for (int i = 0; i < arr.size(); i++)
        {
            idxSameValue[arr[i]].push_back(i);
        }
        unordered_set<int> visitedIndex;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        visitedIndex.emplace(0);
        while (!q.empty())
        {
            auto [idx, step] = q.front();
            q.pop();
            if (idx == arr.size() - 1)
            {
                return step;
            }
            int v = arr[idx];
            step++;
            if (idxSameValue.count(v))
            {
                for (auto &i : idxSameValue[v])
                {
                    if (!visitedIndex.count(i))
                    {
                        visitedIndex.emplace(i);
                        q.emplace(i, step);
                    }
                }
                idxSameValue.erase(v);
            }
            if (idx + 1 < arr.size() && !visitedIndex.count(idx + 1))
            {
                visitedIndex.emplace(idx + 1);
                q.emplace(idx + 1, step);
            }
            if (idx - 1 >= 0 && !visitedIndex.count(idx - 1))
            {
                visitedIndex.emplace(idx - 1);
                q.emplace(idx - 1, step);
            }
        }
        return -1;
    }
};
