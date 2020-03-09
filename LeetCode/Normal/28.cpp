#include <iostream>
#include <cstring>
using namespace std;

int strStr(string haystack, string needle)
{
    int nL = needle.length();
    if (nL == 0)
        return 0;
    int hL = haystack.length();
    int nIndex = 0, hIndex = 0;
    while (hIndex < hL && nIndex < nL)
    {
        if (haystack[hIndex] == needle[nIndex])
        {
            hIndex++;
            nIndex++;
        }
        else
        {
            hIndex -= nIndex - 1;
            if (hL - hIndex < nL)
                break;
            nIndex = 0;
        }
    }
    if(nIndex==nL)
        return hIndex-nL;
    return -1;
}

int main()
{
    string s = "mississippi", s2 = "issi";
    cout << strStr(s, s2);
    cin >> s;
}