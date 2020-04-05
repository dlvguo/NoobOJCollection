#include <iostream>
#include <string>
#include <stack>
using namespace std;

int longestValidParentheses(string s)
{
    int len = s.length(), lNum = 0, rNum = 0, maxNum = 0, llNum = 0, rrNum = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            lNum++;
        }
        else
        {
            rNum++;
        }

        if (s[len - i - 1] == '(')
        {
            llNum++;
        }
        else
        {
            rrNum++;
        }

        if (lNum == rNum && maxNum < lNum)
        {
            maxNum = lNum;
        }
        if (llNum == rrNum && maxNum < llNum)
        {
            maxNum = llNum;
        }
        if (rNum > lNum)
        {
            rNum = lNum = 0;
        }

        if (llNum > rrNum)
        {
            llNum = rrNum = 0;
        }
    }
    return maxNum * 2;
}

int main()
{
    string s = "()(()";
    cout << longestValidParentheses(s);
    system("pause");
}