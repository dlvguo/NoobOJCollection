#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a % b)
            return gcd(b, a % b);
        return b;
    }

    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
            return "";
        return str1.substr(0,gcd(str1.size(),str2.size()));
    }
};
