#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int nowCount = 0, totalCount = p.size();
        vector<int> hset1(26, 0), hset2(26, 0);
        if (s.size() < p.size())
            return {};

        //计算p hsetCount
        for (int i = 0; i < p.size(); i++)
        {
            hset1[s[i] - 'a']++;
            hset2[p[i] - 'a']++;
        }
        vector<int> ans;
        if (hset1 == hset2)
            ans.push_back(0);
        for (int i = p.size(), num = i - p.size(); i < s.size(); i++, num++)
        {

            hset1[s[num] - 'a']--;
            hset1[s[i] - 'a']++;
            if (hset1 == hset2)
                ans.push_back(num + 1);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string s1 = "cbaebabacd", s2 = "abc";
    s.findAnagrams(s1, s2);
}