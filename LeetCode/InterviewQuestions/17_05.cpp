#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }

    vector<string> findLongestSubarray(vector<string> &array)
    {
        unordered_map<int, int> m;

        int sum = 0;
        m[0] = 0;

        int start = 0, end = -1;

        for (int i = 0; i < array.size(); i++)
        {
            int num = isdigit(array[i][0]) ? 1 : -1;
            sum += num;
            if (m.find(sum) != m.end())
            {
                int index = m[sum];
                if (end == -1 || (end - start) < (i - index))
                {
                    start = index;
                    end = i;
                }
            }
            else
            {
                // 注意这种下标要在后面些
                m[sum] = i + 1;
            }
        }
        return vector<string>(array.begin() + start, array.begin() + end + 1);
    }
};