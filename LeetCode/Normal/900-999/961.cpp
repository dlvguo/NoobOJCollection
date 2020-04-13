#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int repeatedNTimes(vector<int> &A)
    {
        bool tag[10000]{false};
        for (int a : A)
        {
            if (tag[a])
                return a;
            else
                tag[a] = true;
        }
        return 0;
    }
};