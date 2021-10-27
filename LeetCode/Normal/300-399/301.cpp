#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string str)
    {
        int count = 0;

        for (char c : str)
        {
            if (c == '(')
            {
                count++;
            }
            else if (c == ')')
            {
                count--;
                if (count < 0)
                {
                    return false;
                }
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> ans;
        unordered_set<string> currSet;

        currSet.insert(s);
        while (true)
        {
            for (auto &str : currSet)
            {
                if (isValid(str))
                    ans.emplace_back(str);
            }
            if (ans.size() > 0)
            {
                return ans;
            }
            unordered_set<string> nextSet;
            for (auto &str : currSet)
            {
                for (int i = 0; i < str.size(); i++)
                {
                    if (i > 0 && str[i] == str[i - 1])
                    {
                        continue;
                    }
                    if (str[i] == '(' || str[i] == ')')
                    {
                        nextSet.insert(str.substr(0, i) + str.substr(i + 1, str.size()));
                    }
                }
            }
            currSet = nextSet;
        }
    }
};
