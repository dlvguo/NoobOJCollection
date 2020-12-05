#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freq;
        for (char ch : tasks)
        {
            ++freq[ch];
        }

        // 任务总数
        int m = freq.size();
        vector<int> nextValid, rest;
        for (auto [_, v] : freq)
        {
            nextValid.push_back(1);
            rest.push_back(v);
        }

        int time = 0;
        for (int i = 0; i < tasks.size(); ++i)
        {
            ++time;
            int minNextValid = INT_MAX;
            for (int j = 0; j < m; ++j)
            {
                if (rest[j])
                {
                    minNextValid = min(minNextValid, nextValid[j]);
                }
            }
            time = max(time, minNextValid);
            int best = -1;
            for (int j = 0; j < m; ++j)
            {
                if (rest[j] && nextValid[j] <= time)
                {
                    if (best == -1 || rest[j] > rest[best])
                    {
                        best = j;
                    }
                }
            }
            nextValid[best] = time + n + 1;
            --rest[best];
        }

        return time;
    }
};
