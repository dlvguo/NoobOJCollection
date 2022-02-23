#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    bool check(char ch)
    {
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
            return false;
        return true;
    }

    string reverseOnlyLetters(string s)
    {
        vector<int> indexs;
        string chs;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (check(s[i]))
            {
                indexs.push_back(i);
                chs.push_back(s[i]);
            }
            else
                temp.push_back(s[i]);
        }
        reverse(temp.begin(), temp.end());
        string res = "";
        int l = 0, ll = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (l < indexs.size() && i == indexs[l])
            {
                res.push_back(chs[l++]);
            }
            else
            {
                res.push_back(temp[ll++]);
            }
        }
        return res;
    }
};