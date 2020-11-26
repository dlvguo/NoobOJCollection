#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef long long LL;

    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        unordered_map<int, int> hashMap;
        LL ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                LL sumAB = A[i] + B[j];
                if (hashMap.find(sumAB) != hashMap.end())
                {
                    hashMap[sumAB]++;
                }
                else
                {
                    hashMap[sumAB] = 1;
                }
            }
        }
        for (int i = 0; i < C.size(); i++)
        {
            for (int j = 0; j < D.size(); j++)
            {
                LL sumCD = C[i] + D[j];
                if (hashMap.find(-sumCD) != hashMap.end())
                {
                    ans += hashMap[-sumCD];
                }
            }
        }
        return ans;
    }
};