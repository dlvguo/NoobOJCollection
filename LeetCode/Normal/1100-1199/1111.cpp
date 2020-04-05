#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //很迷的题目 不过思路跟我想的一样 只不过这个%2
    vector<int> maxDepthAfterSplit(string seq)
    {
        int deep = 0;
        vector<int> v;
        for (int i = 0; i < seq.size(); i++)
        {
            if (seq[i] == '(')
            {
                deep++;
                v.push_back(deep % 2);
            }
            else
            {
                v.push_back(deep % 2);
                deep--;
            }
        }
        return v;
    }
};