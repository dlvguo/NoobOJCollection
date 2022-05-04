#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkN(string &str)
    {
        int index = 0;
        while (str[index] != ' ')
            index++;
        index++;
        return str[index] >= '0' && str[index] <= '9';
    }

    bool static cmp(string &str1, string &str2)
    {
        string temp1 = "", temp_1 = "", temp2 = "", temp_2 = "";
        int index = 0;
        while (str1[index] != ' ')
            temp1.push_back(str1[index++]);
        index++;
        while (index < str1.size())
        {
            temp_1.push_back(str1[index++]);
        }

        index = 0;
        while (str2[index] != ' ')
            temp2.push_back(str2[index++]);
        index++;
        while (index < str2.size())
        {
            temp_2.push_back(str2[index++]);
        }
        return temp_1 == temp_2 ? temp1 < temp2 : temp_1 < temp_2;
    }

    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> sv, nv;
        for (auto log : logs)
            if (checkN(log))
                nv.push_back(log);
            else
                sv.push_back(log);
        sort(sv.begin(), sv.end(), cmp);
        for (int i = 0; i < nv.size(); i++)
            sv.push_back(nv[i]);
        return sv;
    }
};