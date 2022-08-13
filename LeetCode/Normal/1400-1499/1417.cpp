#include <bits/stdc++.h>
using namespace std;
class Solution
{
#define b1 48 <= s[i] && s[i] <= 57
#define b2 c[0][0] < c[1][0]
#define mn min(c[0][0], c[1][0])
#define mx max(c[0][0], c[1][0])
public:
    string reformat(string s)
    {
        short b3 = 0, j = -1, c[2][501];
        memset(c, 0, sizeof(c));
        for (short i = 0; i < s.length(); i++)
            c[b1][++c[b1][0]] = s[i];
        if (mx - mn > 1)
            return "";
        if (mx ^ mn)
            s[++j] = c[b3 = b2][c[b2][0]], --c[b2][0];
        for (short i = 1; i <= c[0][0]; i++)
            s[++j] = c[b3 ^ 1][i], s[++j] = c[b3][i];
        return s;
    }
};
