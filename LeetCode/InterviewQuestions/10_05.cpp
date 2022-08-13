#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findString(vector<string> &words, string s)
    {
        int l = 0, r = words.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (words[mid].size() == 0)
            {
                int lm = mid - 1;
                int rm = mid + 1;
                while (lm >= l || rm < r)
                {
                    if (lm >= l)
                    {
                        if (words[lm].size())
                        {
                            mid = lm;
                            break;
                        }
                        lm--;
                    }
                    if (rm < r)
                    {
                        if (words[rm].size())
                        {
                            mid = rm;
                            break;
                        }
                        rm++;
                    }
                }
            }
            if (words[mid].size() == 0)
                return -1;
            if (words[mid] == s)
                return mid;
            else if (words[mid] < s)
                l = mid + 1;
            else
                r = mid - 1;
            /* code */
        }
        return -1;
    }
};