#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int remain = numBottles;
        int res = numBottles;
        while (remain >= numExchange)
        {
            int num = remain / numExchange;
            res += num;
            remain = remain % numExchange + num;
        }
        return res;
    }
};