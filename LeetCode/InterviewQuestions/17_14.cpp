#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> smallestK(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, less<int>> q;
        //注意边界问题
        if (!arr.size() || !k)
            return {};
        for (int i = 0; i < k; i++)
        {
            q.push(arr[i]);
        }
        for (int i = k; i < arr.size(); i++)
        {
            if (arr[i] < q.top())
            {
                q.pop();
                q.push(arr[i]);
            }
        }
        vector<int> v;
        while (!q.empty())
        {
            v.push_back(q.top());
            q.pop();
        }

        return v;
    }
};
