#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {

        int vis[26] = {0};
        int count = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                count++;
            vis[s1[i] - 'a']++;
            vis[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (vis[i])
                return false;
        return count <= 2;
    }
};