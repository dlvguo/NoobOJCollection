#include <bits/stdc++.h>
#define _DEFINE_DEPRECATED_HASH_CLASSES 0
#include <map>
using namespace std;
class Solution
{
public:
    int ha[1 << 22] = {0};
    const int N = 1e9 + 7;
    //注意组合数
    int countPairs(vector<int> &de)
    {
        int sum = 0;
        for (auto i : de)
        {
            for (int j = 0; j <= 21; ++j)
            { //依次遍历每种可能
                int x = 1 << j;
                if (x - i >= 0 && ha[x - i])
                    sum += ha[x - i] % N, sum %= N;
            }
            ha[i]++;
        }
        return sum % N;
    }
};
