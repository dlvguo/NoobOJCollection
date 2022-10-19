#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int s1 = accumulate(students.begin(), students.end(), 0);
        int s0 = students.size() - s1;
        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (sandwiches[i] == 0 && s0 > 0)
            {
                s0--;
            }
            else if (sandwiches[i] == 1 && s1 > 0)
            {
                s1--;
            }
            else
            {
                break;
            }
        }
        return s0 + s1;
    }
};
