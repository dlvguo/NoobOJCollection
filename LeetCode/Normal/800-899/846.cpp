#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize != 0)
        {
            return false;
        }
        sort(hand.begin(), hand.end());
        unordered_map<int, int> cnt;
        for (auto &num : hand)
        {
            cnt[num]++;
        }
        for (auto &x : hand)
        {
            if (!cnt.count(x))
            {
                continue;
            }
            for (int j = 0; j < groupSize; j++)
            {
                int num = x + j;
                if (!cnt.count(num))
                {
                    return false;
                }
                cnt[num]--;
                if (cnt[num] == 0)
                {
                    cnt.erase(num);
                }
            }
        }
        return true;
    }
};