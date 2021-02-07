#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int l = 0 ,r = 0;
        int usedCost = 0;
        while(r<n){
            usedCost += abs(t[r]-s[r]);
            r++;
            if(usedCost>maxCost){
                usedCost -= abs(t[l]-s[l]);
                l++;
            }
        }
        return n-l;
    }
};
