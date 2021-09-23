#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> ips;
    vector<string> ip;
    void dfs(string s, int start, int remain, int l)
    {
        if (l == 0 && remain == 0)
        {
            ips.push_back(ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3]);
        }
        //避免超出
        if (remain < l || l * 3 < remain)
            return;
        ip.push_back(s.substr(start, 1));
        dfs(s, start + 1, remain - 1, l - 1);
        ip.pop_back();
        //考虑2个和3个
        if (s[start] != '0')
        {
            if (remain >= 2)
            {
                ip.push_back(s.substr(start, 2));
                dfs(s, start + 2, remain - 2, l - 1);
                ip.pop_back();
            }
            if (remain > 2)
            {
                int n = atoi(s.substr(start, 3).c_str());
                if (n <= 255)
                {
                    ip.push_back(s.substr(start, 3));
                    dfs(s, start + 3, remain - 3, l - 1);
                    ip.pop_back();
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4 || s.size() > 12)
            return ips;
        dfs(s, 0, s.size(), 4);
        return ips;
    }
};