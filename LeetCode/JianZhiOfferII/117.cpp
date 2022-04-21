#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(const string &str1, const string &str2, int len)
    {
        int num = 0;
        for (int i = 0; i < len; i++)
        {
            if (str1[i] != str2[i])
            {
                num++;
                if (num > 2)
                    return false;
            }
        }
        return true;
    }

    int uset[303] = {0};
    int search(int x)
    {
        if (uset[x] == x)
            return x;
        return uset[x] = search(uset[x]);
    }

    void unionset(int a, int b)
    {
        int af = search(a), bf = search(b);
        if (af != bf)
            uset[bf] = af;
    }

    int numSimilarGroups(vector<string> &strs)
    {
        int m = strs.size(), len = strs[0].size();
        for (int i = 0; i < m; i++)
            uset[i] = i;

        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                if (check(strs[i], strs[j], len))
                    unionset(i, j);
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++)
        {
            if (uset[i] == i)
                res++;
        }
        return res;
    }
};