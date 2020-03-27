#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool static cmp(const string str, const string str2)
    {
        return str < str2;
    }

    bool count(const string str1, const string str2)
    {
        int sum = 0;
        int index = 0, point = min(str1.size(), str2.size());
        while (index < point && str1[index] == str2[index])
        {
            index++;
            sum++;
        }
        return index == point;
    }

    int minimumLengthEncoding(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            reverse(words[i].begin(), words[i].end());
        }
        sort(words.begin(), words.end(), cmp);
        int sum = 0;
        bool flag;
        for (int i = 1; i < words.size(); i++)
        {
            flag = count(words[i - 1], words[i]);
            if (!flag)
            {
                sum += words[i - 1].size() + 1;
            }
        }
        sum += words.back().size() + 1;
        return sum;
    }
};

int main()
{
    Solution s1;
    vector<string> vts({"time", "atime", "btime"});
    s1.minimumLengthEncoding(vts);
}