#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (flowerbed.size() == 1)
        {
            //0的话可以不种
            if (flowerbed[0] == 0)
                return n == 1;
            return n == 0;
        }
        if (!flowerbed[0] && flowerbed[1] == 0)
        {
            flowerbed[0] = 1;
            n--;
        }
        for (int i = 1; i < flowerbed.size() - 1 && n; i++)
        {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        if (flowerbed.back() == 0 && flowerbed[flowerbed.size() - 2] == 0)
        {
            n--;
        }
        return n <= 0;
    }
};