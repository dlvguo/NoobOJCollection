#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        int _maxc = releaseTimes[0];
        char ch = keysPressed[0];
        for (int i = 1; i < releaseTimes.size(); i++)
        {
            int temp = releaseTimes[i] - releaseTimes[i - 1];
            if (temp > _maxc)
            {
                _maxc = temp;
                ch = keysPressed[i];
            }
            else if (temp == _maxc && keysPressed[i] > ch)
            {
                ch = keysPressed[i];
            }
        }
        return ch;
    }
};