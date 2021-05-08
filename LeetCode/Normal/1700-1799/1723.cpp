#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool backtrack(vector<int> &jobs, vector<int> &workloads, int idx, int limit)
    {
        if (idx >= jobs.size())
        {
            return true;
        }
        int cur = jobs[idx];
        for (auto &workload : workloads)
        {
            if (workload + cur <= limit)
            {
                workload += cur;
                if (backtrack(jobs, workloads, idx + 1, limit))
                {
                    return true;
                }
                workload -= cur;
            }
            // 如果当前工人未被分配工作，那么下一个工人也必然未被分配工作
            // 或者当前工作恰能使该工人的工作量达到了上限
            // 这两种情况下我们无需尝试继续分配工作
            if (workload == 0 || workload + cur == limit)
            {
                break;
            }
        }
        return false;
    }

    bool check(vector<int> &jobs, int k, int limit)
    {
        vector<int> workloads(k, 0);
        return backtrack(jobs, workloads, 0, limit);
    }

    int minimumTimeRequired(vector<int> &jobs, int k)
    {
        sort(jobs.begin(), jobs.end(), greater<int>());
        int l = jobs[0], r = accumulate(jobs.begin(), jobs.end(), 0);
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(jobs, k, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};
