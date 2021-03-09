#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //注意一次只删除俩个 而不是一把删
    string removeDuplicates(string S)
    {
        bool tag = false;
        int preIndex = 0;
        string str = "";

        for (int i = 0; i < S.length(); i++)
        {
            if (i != S.length() - 1)
            {
                if (S[i] == S[i + 1])
                {
                    i++;
                    tag = true;
                    continue;
                }
            }
            str += S[i];
        }
        return tag ? removeDuplicates(str) : str;
    }
};