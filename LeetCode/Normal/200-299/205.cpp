#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            char x = s[i], y = t[i];
            //如果存在映射 不同就返回
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x))
            {
                return false;
            }
            // 双映射
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};

int main()
{
    Solution sl;
    string s = "aa", t = "ab";
    cout << sl.isIsomorphic(s, t);
    system("pause");
}
