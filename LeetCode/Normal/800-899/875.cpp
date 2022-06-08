#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &piles, int h, int eat)
    {

        int temp = 0;
        for (auto pile : piles)
        {
            temp += pile / eat;
            if (pile % eat)
                temp++;
            if (temp > h)
                return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        sort(piles.begin(), piles.end());

        int res = piles.back();

        int l = 1, r = res - 1;

        while (l <= r)
        {
            int mid = (l + r) >> 1;

            //如果能吃到说明右移
            if (check(piles, h, mid))
            {
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return res;
    }
};