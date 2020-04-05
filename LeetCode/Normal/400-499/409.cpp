#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int a[26] = {0};
        int A[26] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a')
            {
                a[s[i] - 'a']++;
            }
            else
            {
                A[s[i] - 'A']++;
            }
        }
        int sum = 0;
        for (int i = 0; i < 26; i++)
        {
            if (a[i] % 2)//SB了奇数-1就偶数了！！！
            {
                sum += a[i] - 1;
            }
            else
            {
                sum += a[i];
            }
            if (A[i] % 2)
            {
                sum += A[i] - 1;
            }
            else
            {

                sum += A[i];
            }
        }
        return sum == s.size() ? sum : sum + 1;//考虑是否有多余的字母放中间
    }
};