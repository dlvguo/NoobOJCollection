#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        int row = 0, nowWidth = 0;
        for (auto ch : s)
        {
            int temp = widths[ch - 'a'];
            if (temp + nowWidth > 100)
            {
                row++;
                nowWidth = temp;
            }
            else
                nowWidth += temp;
        }
        return { row + 1, nowWidth };
    }
};