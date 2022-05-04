#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> qu;
        for (int i = 1; i <= n; i++)
        {
            qu.emplace(i);
        }
        while (qu.size() > 1)
        {
            for (int i = 1; i < k; i++)
            {
                qu.emplace(qu.front());
                qu.pop();
            }
            qu.pop();
        }
        return qu.front();
    }
};
