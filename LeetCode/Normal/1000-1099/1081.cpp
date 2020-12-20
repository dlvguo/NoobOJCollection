#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string smallestSubsequence(string s)
    {
        int nums[26] = {0}, vis[26] = {0};
        // 使用单调栈操作
        string str;
        for (int i = 0; i < s.size(); i++)
        {
            nums[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (!vis[s[i] - 'a'])
            {
                while (!str.empty() && str.back() > s[i])
                {
                    if (nums[str.back() - 'a'])
                    {
                        vis[str.back() - 'a'] = 0;
                        str.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
                vis[s[i] - 'a'] = 1;
                str.push_back(s[i]);
            }
            nums[s[i] - 'a']--;
        }
        return str;
    }
};