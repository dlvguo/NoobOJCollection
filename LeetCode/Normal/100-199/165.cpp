#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int left = 0, right = 0;
        int lnum = 0, rnum = 0;
        while (left < version1.size() || right < version2.size())
        {
            lnum = 0, rnum = 0;
            while (left < version1.size() && version1[left] != '.')
            {
                lnum = lnum * 10 + version1[left++] - '0';
            }
            while (right < version2.size() && version2[right] != '.')
            {
                rnum = rnum * 10 + version2[right++] - '0';
            }
            left++, right++;
            if (lnum != rnum)
                break;
        }
        if (lnum > rnum)
            return 1;
        else if (lnum < rnum)
            return -1;
        return 0;
    }
};
