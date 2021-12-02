#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool static cmp(int a, int b)
    {
        return a > b;
    }

    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<string> res(score.size());
        unordered_map<int, int> umap;

        for (int i = 0; i < score.size(); i++)
        {
            umap[score[i]] = i;
        }
        sort(score.begin(), score.end(), cmp);
        res[umap[score[0]]] = "Gold Medal";
        if (score.size() > 1)
            res[umap[score[1]]] = "Silver Medal";
        if (score.size() > 2)
            res[umap[score[2]]] = "Bronze Medal";

        for (int i = 3; i < score.size(); i++)
        {
            res[umap[score[i]]] = to_string(i + 1);
        }
        return res;
    }
};