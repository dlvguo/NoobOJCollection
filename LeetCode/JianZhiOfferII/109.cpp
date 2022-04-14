#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> dset;
        unordered_set<string> vset;
        for (auto dead : deadends)
            dset.insert(dead);
        queue<string> sq;
        if (dset.find("0000") != dset.end())
            return -1;
        sq.push("0000");
        vset.insert("0000");
        int cen = 0;
        while (sq.size())
        {
            int num = sq.size();
            while (num--)
            {
                string str = sq.front();
                if (str == target)
                    return cen;
                sq.pop();
                for (int i = 0; i < 4; i++)
                {
                    string temp = str;
                    char ch = temp[i] + 1;
                    if (ch > '9')
                        ch = '0';
                    temp[i] = ch;
                    if (vset.find(temp) == vset.end() && dset.find(temp) == dset.end())
                    {
                        vset.insert(temp);
                        sq.push(temp);
                    }
                    temp = str;
                    ch = temp[i] - 1;
                    if (ch < '0')
                        ch = '9';
                    temp[i] = ch;
                    if (vset.find(temp) == vset.end() && dset.find(temp) == dset.end())
                    {
                        vset.insert(temp);
                        sq.push(temp);
                    }
                }
            }
            cen++;
        }
        return -1;
    }
};