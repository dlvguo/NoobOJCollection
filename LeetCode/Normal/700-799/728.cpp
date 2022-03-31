#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //注意数的变化
    bool search(int num)
    {
        int temp = num;
        while (num)
        {
            int mask = num % 10;
            if (mask == 0)
                return false;
            if (temp % mask)
                return false;
            num /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        while (left <= right)
        {
            if (search(left))
                res.push_back(left);
            left++;
        }
        return res;
    }
};