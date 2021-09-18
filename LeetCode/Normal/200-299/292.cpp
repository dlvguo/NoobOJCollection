#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //巴什博弈 取1-m个 若n不能被m+1整除则先手胜利
    bool canWinNim(int n)
    {
        return n % 4;
    }
};