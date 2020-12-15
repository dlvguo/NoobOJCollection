#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int monotoneIncreasingDigits(int N)
    {
        string str = to_string(N);
        int max = -1, idx = -1;
        for (int i = 0; i < str.size() - 1; i++)
        {
            if (max < str[i])
            {
                max = str[i];
                idx = i;
            }
            if (str[i] > str[i + 1])
            {
                str[idx] -= 1;
                for (int j = idx + 1; j < str.size(); j++)
                {
                    str[j] = '9';
                }
                break;
            }
        }
        return stoi(str);
    }
};