#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(string s)
    {
        int l = s[0] == '0' ? 1 : 0;
        int r = 0;
        for (int i = 1; i < s.size(); i++)
            if (s[i] == '1')
                r++;
        int _max = l + r;
        for (int i = 1; i < s.size() - 1; i++)
        {
            if (s[i] == '1')
                r--;
            else
                l++;
            _max = max(l + r, _max);
        }
        return _max;
    }
};
int main(){
    Solution s;
    cout<<s.maxScore("11111");
}