#include <bits/stdc++.h>
#include <map>
#include <queue>
using namespace std;
class Solution
{

    struct node
    {
        string word;
        int count;
    };

    struct cmp1
    {
        bool operator()(node &a, node &b)
        {
            if (a.count == b.count)
                return a.word > b.word;
            return a.count < b.count;
        }
    };

public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        sort(words.begin(), words.end());
        priority_queue<node, vector<node>, cmp1> q;
        int count = 1;
        for (int i = 1; i < words.size(); i++)
        {
            if (words[i] == words[i - 1])
                count++;
            else
            {
                node n;
                n.word = words[i - 1];
                n.count = count;
                count = 1;
                q.push(n);
            }
        }
        node n;
        n.word = words.back();
        n.count = count;
        q.push(n);
        vector<string> strs;
        while (k--)
        {
            strs.push_back(q.top().word);
            q.pop();
        }
        return strs;
    }
};