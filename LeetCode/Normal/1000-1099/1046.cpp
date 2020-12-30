#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int, vector<int>, less<int>> p;
        for (int i = 0; i < stones.size(); i++)
        {
            p.push(stones[i]);
        }
        while (p.size() > 0)
        {
            int x = p.top();
            p.pop();
            int y = p.top();
            p.pop();
            if (x > y)
            {
                p.push(x - y);
            }
        }
        return p.size() == 0 ? 0 : p.top();
    }
};