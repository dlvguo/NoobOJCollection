#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int l = 0, r = 0, tempk = k, ans = 0;
        //遍历最长key
        while (r < answerKey.size())
        {
            if (answerKey[r++] == 'F')
                tempk--;
            //说明这个界超了 找到第一个F剔除
            if (tempk < 0)
            {
                while (l < r && answerKey[l] != 'F')
                {
                    l++;
                }
                l++;
                tempk++;
            }
            else
            {
                ans = max(ans, r - l);
            }
        }
        ans = max(ans, r - l);
        tempk = k;
        l = 0, r = 0;
        while (r < answerKey.size())
        {
            if (answerKey[r++] == 'T')
                tempk--;
            //说明这个界超了 找到第一个F剔除
            if (tempk < 0)
            {
                while (l < r && answerKey[l] != 'T')
                {
                    l++;
                }
                l++;
                tempk++;
            }
            else
            {
                ans = max(ans, r - l);
            }
        }
        ans = max(ans, r - l);
        return ans;
    }
};

int main()
{
    Solution s;
    string s = "TFFT";
    int k = 1;
    s.maxConsecutiveAnswers(s, k);
}