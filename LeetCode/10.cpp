#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isMatch(char *s, char *p)
{
    int slen = strlen(s), plen = strlen(p), sindex = 0, pindex = 0;
    int musIndex=0;
    while (sindex < slen && pindex < plen)
    {
        if (p[pindex] == '.')
        {
            if (pindex + 1 != plen)
            {
                if (p[pindex + 1] == '*')
                {
                    pindex+=2;

                    return true;
                }
            }
            pindex++;
            sindex++;
        }
        else
        {
            if (pindex + 1 != plen)
            {
                if (p[pindex + 1] == '*')
                {
                    while (sindex < slen && s[sindex] == p[pindex])
                    {
                        sindex++;
                    }
                    pindex += 2;
                    //再来一波那种判断 如果后面的数字相等就回消
                    //计算后面有几个相同的
                    int temp = pindex - 2, tempindex = sindex - 1;
                    while (pindex < plen && p[pindex] == p[temp])
                    {
                        if (p[pindex] != s[tempindex--])
                            return false;
                        pindex++;                        
                    }
                    continue;
                }
            }
            if (s[sindex] != p[pindex])
                return false;
            pindex++;
            sindex++;
        }
    }
    if (sindex >= slen && pindex >= plen)
        return true;
    return false;
}

int main()
{
    char *s = "aaa", *p = "ab*c*a*a";
    cout << isMatch(s, p);
}