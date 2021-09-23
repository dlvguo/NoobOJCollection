#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<string> vts(numRows, "");
        string str;
        int index = 0, temp = 0;
        while (index < s.size())
        {
            for (temp = 0; temp < numRows && index < s.size(); temp++)
            {
                //放到temp
                vts[temp].push_back(s[index++]);
            }
            if (temp == numRows)
            {
                for (temp = numRows - 2; temp > 0 && index < s.size(); temp--)
                {
                    vts[temp].push_back(s[index++]);
                    for (int i = 0; i < numRows; i++)
                    {
                        if (i != temp)
                            vts[i].push_back(' ');
                    }
                }
            }
            //说明index完成了
            else
            {
                for (int i = temp; i < numRows; i++)
                {
                    vts[i].push_back(' ');
                }
            }
        }
        for (int i = 0; i < numRows - 1; i++)
        {
            vts[i].push_back('\n');
        }
        for (int i = 0; i < numRows; i++)
        {
            str += vts[i];
        }
        return str;
    }
};