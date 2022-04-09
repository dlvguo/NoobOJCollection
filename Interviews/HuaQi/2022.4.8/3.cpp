#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 请写一个方法，输入是一个字符串 word，这个方法会验证这个输入的字符串是不是只由"ci", "ti" 和 "bank"组成的连续字符串，因而可以被琪琪读出来。
如果能被读出来，返回"YES", 否则返回"NO"。（返回值是大写字母字符串，不需要包含引号）
     * @param word string字符串 只会是小写字母a-z，无需考虑大写字母，数字符号，空格等其他情况。长度为最小1，最长58。
     * @return string字符串
     */

    bool check(string s, string s2, int index)
    {
        int sIndex = 0;
        while (index < s2.size() && sIndex < s.size() && s[sIndex] == s2[index])
        {
            sIndex++;
            index++;
        }
        return sIndex == s.size();
    }

    string check(string word)
    {

        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == 't')
            {
                if (check("ti", word, i))
                {
                    i += 1;
                }
                else
                    return "NO";
            }
            else if (word[i] == 'c')
            {
                if (check("ci", word, i))
                {
                    i += 1;
                }
                else
                    return "NO";
            }
            else if (word[i] == 'b')
            {
                if (check("bank", word, i))
                {
                    i += 3;
                }
                else
                    return "NO";
            }
            else
                return "NO";
        }
        return "YES";
        // write code here
    }
};