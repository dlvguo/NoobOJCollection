#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        int dp[27] = {0};
        int temp[27] = {0};
        vector<string> vts;
        for (int j = 0; j < A[0].size(); j++)
        {
            dp[A[0][j] - 'a']++;
        }
        for (int i = 1; i < A.size(); i++)
        {
            string t = A[i];
            for (int j = 0; j < t.size(); j++)
            {
                if (temp[t[j] - 'a'] < dp[t[j] - 'a'])
                {
                    temp[t[j] - 'a']++;
                }
            }
            for (int k = 0; k < 26; k++)
            {
                dp[k] = temp[k];
                temp[k] = 0;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            char a = i + 'a';
            string s(1, a);
            while (dp[i]--)
            {
                vts.push_back(s);
            };
        }
        return vts;
    }
};

int main()
{
    vector<string> s = {"bella", "label", "roller"};
    Solution s1;
    s1.commonChars(s);
}