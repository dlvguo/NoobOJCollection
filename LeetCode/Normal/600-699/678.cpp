#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkValidString(string s)
    {
        int lnum = 0, rnum = 0, xnum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                lnum++;
            else if (s[i] == '*'){
                if(lnum==0)
                {
                    
                }
            }
                
            else
            {
                if (lnum)
                    lnum--;
                else if (xnum)
                    xnum--;
                else
                    return false;
            }
        }
        if (lnum)
            return false;
        return true;
    }
};

int main()
{
    string s = "****(((*(";
    Solution s1;
    cout << s1.checkValidString(s);
}