#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        return s.find("01") == string::npos;
    }
};
