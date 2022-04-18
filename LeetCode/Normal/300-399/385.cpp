#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int index = 0;

    NestedInteger deserialize(string s)
    {
        if (s[index] == '[')
        {
            index++;
            NestedInteger ni;
            while (s[index] != ']')
            {
                ni.add(deserialize(s));
                if (s[index] == ',')
                {
                    index++;
                }
            }
            index++;
            return ni;
        }
        else
        {
            bool negative = false;
            if (s[index] == '-')
            {
                negative = true;
                index++;
            }
            int num = 0;
            while (index < s.size() && isdigit(s[index]))
            {
                num = num * 10 + s[index] - '0';
                index++;
            }
            if (negative)
            {
                num *= -1;
            }
            return NestedInteger(num);
        }
    }
};
