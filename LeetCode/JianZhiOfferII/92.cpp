#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        // dp2代表转0的次数 dp1代表转1的次数
        vector<int> dp1(s.size()), dp2(s.size());
        if (s[0] == '1')
            dp2[0] = 1;
        else
            dp1[0] = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if(s[i]=='1'){
                dp1[i]=dp1[i-1];
                
            }
        }
        
    }
};