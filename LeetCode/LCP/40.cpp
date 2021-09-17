#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxmiumScore(vector<int> &cards, int cnt)
    {
        vector<int> jnums, onums;
        for (int i = 0; i < cards.size(); i++)
        {
            //说明奇数
            if (cards[i] % 2)
            {
                jnums.push_back(cards[i]);
            }
            else
            {
                onums.push_back(cards[i]);
            }
        }
        sort(jnums.rbegin(), jnums.rend());
        sort(onums.rbegin(), onums.rend());
        for (int i = 1; i < jnums.size(); i++)
        {
            jnums[i] += jnums[i - 1];
        }
        for (int i = 1; i < onums.size(); i++)
        {
            onums[i] += onums[i - 1];
        }

        int ans = 0, sum = 0;
        for (int i = 0; i <= jnums.size(); i += 2)
        {
            if (cnt - i <= onums.size())
            {
                if (cnt - i == 0)
                {
                    sum = jnums[i - 1];
                }
                else
                {
                    if (i != 0)
                        sum = jnums[i - 1] + onums[cnt - i - 1];
                    else
                        sum = onums[cnt - i - 1];
                }
            }
            ans = max(ans, sum);
        }

        return ans;
    }
};
