#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseVowels(string s)
    {
        vector<int> is;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c <= 'Z')
                c += 32;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                is.push_back(i);
        }
        int l = 0, r = is.size() - 1;
        while (l < r)
        {
            swap(s[is[l++]], s[is[r--]]);
        }
        return s;
    }
};