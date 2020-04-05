#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string compressString(string S)
    {
        string str;
        if (S.length() == 0)
            return S;
        int Count = 1, index = 1, preIndex = 0;
        while (str.size() < S.size() && index < S.size())
        {
            if (S[index] == S[preIndex])
            {
                Count++;
            }
            else
            {
                str += S[preIndex] + to_string(Count);
                preIndex = index;
                Count = 1;
            }
            index++;
        }
        str += S[preIndex] + to_string(Count);
        if (str.size() < S.size())
            return str;
        return S;
    }
};

int main()
{
    Solution s1;
    string s = "aabcccccaa";
    s1.compressString(s);
}
