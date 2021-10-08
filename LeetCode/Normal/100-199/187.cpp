#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> m;
        if (s.size() < 10)
            return {};

        for (int i = 0; i < s.size() - 9; i++)
        {
            m[s.substr(i, 10)]++;
        }
        vector<string> res;
        for (auto _m : m)
        {
            if (_m.second > 1)
            {
                res.push_back(_m.first);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    s.findRepeatedDnaSequences("A");
}