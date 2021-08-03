#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct node
    {
        int k, v;
        bool operator<(const node &other) const //升序排序
        {
            if (v == other.v)
                return k < other.k;
            return v < other.v;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<node> nts;
        for (int i = 0; i < mat.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j])
                    count++;
            }
            node n;
            n.k = i;
            n.v = count;
            nts.push_back(n);
        }
        sort(nts.begin(), nts.end());
        vector<int> v;
        for (int i = 0; i < k; i++)
            v.push_back(nts[i].k);
        return v;
    }
};