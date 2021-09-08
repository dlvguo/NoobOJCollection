#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// int strStr(string haystack, string needle)
// {
//     int nL = needle.length();
//     if (nL == 0)
//         return 0;
//     int hL = haystack.length();
//     int nIndex = 0, hIndex = 0;
//     while (hIndex < hL && nIndex < nL)
//     {
//         if (haystack[hIndex] == needle[nIndex])
//         {
//             hIndex++;
//             nIndex++;
//         }
//         else
//         {
//             hIndex -= nIndex - 1;
//             if (hL - hIndex < nL)
//                 break;
//             nIndex = 0;
//         }
//     }
//     if(nIndex==nL)
//         return hIndex-nL;
//     return -1;
// }

int strStr(string haystack, string needle)
{
    //KMP计算next数组
    vector<int> next(needle.size(), 0);
    //获取next数组
    int j = 0; //代表前缀和后缀最长的数组

    for (int i = 1; i < needle.size(); i++)
    {
        while (j > 0 && needle[j] != needle[i])
        {
            j = next[j - 1];
        }
        if (needle[j] == needle[i])
            next[i] = ++j;
    }

    int hIndex = 0, nIndex = 0;

    while (hIndex < haystack.size() && nIndex < needle.size())
    {
        if (haystack[hIndex] == needle[nIndex])
        {
            nIndex++;
            hIndex++;
        }
        else
        {
            if (nIndex != 0)
                nIndex = next[nIndex - 1];
            else
                hIndex++;
        }
    }
    if (nIndex == needle.size())
        return hIndex - nIndex;
    return -1;
}

int main()
{
    //
    string s = "mississippi", s2 = "issip";
    cout << strStr(s, s2);
}