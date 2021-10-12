#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {
        return (int) ((sqrt((long long) 8 * n + 1) - 1) / 2);
    }
};

