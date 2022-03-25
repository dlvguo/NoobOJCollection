#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        unordered_map<int, int> _map;
        int res = 0;
        for (int i = 5,count=1; i <= n; i += 5,count++)
        {
            int num = i;
            while (num)
            {
                if (!num % 5)
                    res++;
                else
                    break;
                num /= 5;
            }
        }
        return res;
    }
};

int main()
{
}