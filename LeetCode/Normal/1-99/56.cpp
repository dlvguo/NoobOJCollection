#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     struct cmp
    {
        bool operator()(vector<int> &v1, vector<int> &v2)
        {
            return v1[0] > v2[0];
        }
    };

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if(intervals.size()==0)
            return intervals;
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for (int i = 0; i < intervals.size(); i++)
        {
            pq.push(intervals[i]);
        }
        vector<vector<int>> m;
        vector<int> v1, v2;
        while (pq.size() > 1)
        {
            v1 = pq.top();
            pq.pop();
            //说明包含在里面
            if (pq.top()[1] <= v1[1])
            {
                pq.pop();
                pq.push(v1);
            }
            else if (pq.top()[0] <= v1[1])
            {
                v1[1] = pq.top()[1];
                pq.pop();
                pq.push(v1);
            }
            else
            {
                m.push_back(v1);
            }
        }
        m.push_back(pq.top());
        return m;
    }
};