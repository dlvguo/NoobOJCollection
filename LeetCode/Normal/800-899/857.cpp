#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        vector<int> h(n, 0);
        iota(h.begin(), h.end(), 0);
        sort(h.begin(), h.end(), [&](int &a, int &b)
             { return quality[a] * wage[b] > quality[b] * wage[a]; });
        double res = 1e9;
        double totalq = 0.0;
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < k - 1; i++)
        {
            totalq += quality[h[i]];
            q.push(quality[h[i]]);
        }
        for (int i = k - 1; i < n; i++)
        {
            int idx = h[i];
            totalq += quality[idx];
            q.push(quality[idx]);
            double totalc = ((double)wage[idx] / quality[idx]) * totalq;
            res = min(res, totalc);
            totalq -= q.top();
            q.pop();
        }
        return res;
    }
};
