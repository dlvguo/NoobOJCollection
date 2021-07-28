#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string maximumTime(string time)
    {
        //注意第二个为大于3时候 2425是错的 变成14
        if (time[0] == '?')
            if (time[1] != '?')
                time[0] = time[1] >= '4' ? '1' : '2';
            else
                time[0] = '2';
        if (time[1] == '?')
            time[1] = time[0] == '2' ? '3' : '9';
        if (time[3] == '?')
            time[3] = '5';
        if (time[4] == '?')
            time[4] = '9';
        return time;
    }
};

int main()
{
    Solution s;
    string t = "??:3?";
    cout << s.maximumTime(t);
}