#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        vector<int> amounts(amount + 1, 0);
        vector<int> counts(amount + 1, 0);
        for (int i = coins.size() - 1; i >= 0; i--)
        {
            for (int v = coins[i]; v <= amount; v++)
            {
                int temp = amounts[v - coins[i]] + coins[i];
                if (temp > amounts[v])
                {
                    amounts[v] = temp;
                    counts[v] = counts[v - coins[i]] + 1;
                }
                else if (temp == amounts[v] && counts[v] > counts[v - coins[i]] + 1) //考虑一个同样的temp下选择少的
                {
                    counts[v] = counts[v - coins[i]] + 1;
                }
            }
        }
        if (amounts[amount] == amount)
        {

            return counts[amount];
        }
        return -1;
    }
};

int main()
{
    vector<int> v = {1, 2, 5};
    Solution s1;
    s1.coinChange(v, 11);
}