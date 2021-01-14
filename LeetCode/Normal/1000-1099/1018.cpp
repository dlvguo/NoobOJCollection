#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &A)
    {
       vector<bool> res;
        int len=A.size();
        int num=0;
        for(int i=0;i<len;++i){
            num=num*2+A[i];
            num%=5;
            if(num==0) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};