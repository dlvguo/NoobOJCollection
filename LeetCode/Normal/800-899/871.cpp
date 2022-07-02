#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int res = 0;
        if (target <= startFuel)
            return res;

        priority_queue<int> pq;

        for (int i = 0; i < stations.size(); i++)
        {
            if (startFuel >= stations[i][0])
            {
                pq.push(stations[i][1]);
            }
            else
            {
                while (pq.size() && startFuel < stations[i][0] && startFuel < target)
                {
                    startFuel += pq.top();
                    pq.pop();
                    res++;
                }
                if (startFuel >= target)
                    return res;
                // 无法到达
                if (startFuel < stations[i][0])
                    return -1;
            }
        }
        return -1;
    }
};