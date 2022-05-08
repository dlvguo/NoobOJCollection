#include <bits/stdc++.h>
using namespace std;
class RecentCounter
{
public:
    queue<int> pq;
    RecentCounter()
    {
    }

    int ping(int t)
    {
        int pre = t - 3000;
        while (pq.size() && pq.front() < pre)
        {
            pq.pop();
        }
        pq.push(t);
        return pq.size();
    }
};