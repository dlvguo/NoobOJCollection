#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        int m = requests.size();
        int res = 0;
        for (int i = 1; i < (1 << m); i++)
        {
            int mask = 1, sum = 0, zeroCnt;
            int cnt[21] = {0};
            for (int l = 1; l <= m && mask <= i; l++)
            {
                if (mask & i)
                {
                    if (++cnt[requests[l - 1][0]] == 1)
                        sum++;
                    if (--cnt[requests[l - 1][1]] == 0)
                        sum--;
                    zeroCnt++;
                }
                mask = mask << 1;
            }
            if (!sum)
                res = max(zeroCnt, res);
        }
        return res;
    }
};