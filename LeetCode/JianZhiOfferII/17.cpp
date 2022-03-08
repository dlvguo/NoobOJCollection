#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int resCount = 0;
        int hs[100] = {0};
        int ts[100] = {0};
        for (auto ch : t)
        {
            hs[ch - 'A']++;
            resCount++;
        }
        int left = 0, right = 0, tempCount = 0;
        int res = INT32_MAX;
        string resStr = "";
        deque<char> dq;
        string str="";
        while (right < s.size())
        {
            int index = s[right] - 'A';
            str.push_back(s[right]);
            if (++ts[index] <= hs[index])
            {
                tempCount++;
            }
            // 满足找到条件
            while (tempCount >= resCount)
            {
                if(res>tempCount){
                    
                }
            }
        }
    }
};