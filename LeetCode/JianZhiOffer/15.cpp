#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while (n)
        {
            n=n&(n-1);//会把最右边的1变成0
            count++;
        }
        return count;
    }
};