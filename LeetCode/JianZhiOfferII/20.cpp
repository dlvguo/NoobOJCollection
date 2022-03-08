#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        int res=0;

        for (int i = 0; i <s.size(); i++)
        {
            res+=figure(s,i,i);
                        res+=figure(s,i,i+1);

        }        
        return res;

    }

    int figure(string s,int start,int end){
        
        int res=0;
        while (start>=0&&end<s.size()&&s[start--]==s[end++])
        {
            res++;
        }
        return res;
    }
};