#include <bits/stdc++.h>
using namespace std;

/*
我们先建立一个数组xor[]，xor[i]存储从arr[0]异或到当前元素arr[i]的值，
如果a^b^c^d^e=xor,那么d^e=(a^b^c)^xor,
于是arr[j]^arr[j+1]^...^arr[k-1]^arr[k]=xor[k]^xor[j-1]，这里k相当于queries[i][1],j相当于queries[i][0],要注意queries[i][0]==0的情况
*/

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        vector<int> xors(n + 1);
        for (int i = 0; i < n; i++)
        {
            xors[i + 1] = xors[i] ^ arr[i];
        }
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++)
        {
            ans[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];
        }
        return ans;
    }
};
