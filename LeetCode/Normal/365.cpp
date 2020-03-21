#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }

    bool canMeasureWater(int x, int y, int z)
    {
        if(z>x+y)//清空一个所以如果多的话就不行
            return false;

        int maxyue = x > y ? gcd(x, y) : gcd(y, x);
        if (maxyue == 0)
            return z == 0;
        return z % maxyue == 0;
    }
};

int main(){
    Solution s1;
    s1.canMeasureWater(1,1,12);
}
