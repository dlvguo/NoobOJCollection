#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    char firstUniqChar(string s)
    {
        int count[55] = {0};
        vector<char> p;
        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            if (count[index] == 0)
            {
                p.push_back(s[i]);
            }
            count[index]++;
        }

        for (int i = 0; i < p.size(); i++)
        {
            if (count[p[i] - 'a'] == 1)
            {
                return p[i];
            }
        }
        return ' ';
    }
};