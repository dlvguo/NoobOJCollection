#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int matrixScore(vector<vector<int>> &A)
    {
        //检索横排
        for (int i = 0; i < A.size(); i++)
        {
            if (!A[i][0])
            {
                for (int j = 0; j < A[0].size(); j++)
                {
                    A[i][j] = !A[i][j];
                }
            }
        }
        //检索竖排
        int s = A.size() % 2 ? A.size() / 2 + 1 : A.size() / 2;
        for (int i = 0; i < A[0].size(); i++)
        {
            int count = 0;
            for (int j = 0; j < A.size(); j++)
            {
                if (A[j][i])
                    count++;
            }
            if (count < s)
                for (int j = 0; j < A.size(); j++)
                    A[j][i] = !A[j][i];
        }
        //计算total
        int ans = 0, mul = 1;
        for (int i = A[0].size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < A.size(); j++)
            {
                ans += A[j][i] * mul;
            }
            mul *= 2;
        }
        return ans;
    }
};