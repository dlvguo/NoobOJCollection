#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        vector<int> v(55, 0);
        for (int i = 0; i < J.length(); i++)
        {
            if (J[i] >= 'a')
            {
                v[J[i] - 'a' + 26] = 1;
            }
            else
            {
                v[J[i] - 'A'] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] >= 'a')
            {
                if (v[S[i] - 'a' + 26])
                    ans++;
            }
            else
            {
                if (v[S[i] - 'A'])
                    ans++;
            }
        }
        return ans;
    }
};
