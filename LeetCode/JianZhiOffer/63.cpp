#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        //n维护当前最小的 然后相减即可

        int n = prices[0];
        int max = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > n)
            {
                max = max > prices[i] - n ? max : prices[i] - n;
            }
            else
            {
                n = prices[i];
            }
        }

        return max;
    }
};