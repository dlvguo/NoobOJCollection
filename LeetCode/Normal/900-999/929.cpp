#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> sset;
        for (auto email : emails)
        {
            string temp = "";
            int index = 0;
            while (email[index] != '+' && email[index] != '@')
            {
                if (email[index] != '.')
                    temp.push_back(email[index]);
                index++;
            }
            if (email[index] == '+')
            {
                while (email[index] != '@')
                {
                    index++;
                }
            }
            while (index < email.size())
            {
                temp.push_back(email[index++]);
            }
            sset.insert(temp);
        }
        return sset.size();
    }
};