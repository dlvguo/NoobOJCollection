#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &A)
    {
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            sum += A[i];
        }
        if (sum % 3)
            return false;
        sum /= 3;
        int count = 0;
        int curSum = 0;
        //
        for (int i = 0; i < A.size(); i++)
        {
            curSum += A[i];
            if (curSum == sum)
            {
                curSum = 0;
                count++;
            }
        }
        return count==3||(count>3&&sum==0);
    }
};