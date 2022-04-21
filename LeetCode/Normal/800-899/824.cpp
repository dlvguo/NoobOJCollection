#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(char ch)
    {
        string str = "aeiouAEIOU";
        for (int i = 0; i < str.size(); i++)
            if (ch == str[i])
                return true;
        return false;
    }

    string toGoatLatin(string sentence)
    {
        string astr = "a";
        string res = "", hz = "";
        if (check(sentence[0]))
            res.push_back(sentence[0]);
        else
            hz = sentence[0];

        for (int i = 1; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                res += hz + "ma" + astr + " ";
                astr.push_back('a');

                if (!check(sentence[i + 1]))
                {
                    hz = sentence[i + 1];
                    i++;
                }
                else
                    hz = "";
            }
            else
                res.push_back(sentence[i]);
        }
        res += hz + "ma" + astr;
        return res;
    }
};