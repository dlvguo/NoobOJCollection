#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        vector<int> nums(26, -1);
        int _max = -1;

        for (int i = 0; i < s.size(); i++)
        {
            int num = s[i] - 'a';
            if (nums[num] == -1)
                nums[num] = i;
            else
            {
                cout << "hh" << endl;
                cout << i << endl;
                cout << nums[num] << endl;
                _max = max(_max, i - nums[num] - 1);
            }
        }
        return _max;
    }
};