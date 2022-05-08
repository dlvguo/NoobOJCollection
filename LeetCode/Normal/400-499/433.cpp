#include <bits/stdc++.h>
using namespace std;
class Solution
{
    const char signs[4] = {'A', 'C', 'G', 'T'};

public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_set<string> sset;
        for (auto b : bank)
            sset.insert(b);
        if (sset.find(end) == sset.end())
            return -1;
        int res = 0;
        if (start == end)
            return res;
        queue<string> pq;
        pq.push(start);
        while (pq.size())
        {
            res++;
            int count = pq.size();
            while (count--)
            {
                string temp = pq.front();
                pq.pop();
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (temp[i] == signs[j])
                            continue;
                        string t = temp;
                        t[i] = signs[j];
                        if (t == end)
                            return res;
                        if (sset.find(t) != sset.end())
                        {
                            pq.push(t);
                            sset.erase(t);
                        }
                    }
                }
            }
        }
        return -1;
    }
};