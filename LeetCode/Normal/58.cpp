#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = s.size() - 1;
        while (len >= 0 && s[len] == ' ')
        {
            len--;
        }
        int index = len;
        while (index >= 0 && s[index] != ' ')
        {
            index--;
        }
        return len - index;
    }
};