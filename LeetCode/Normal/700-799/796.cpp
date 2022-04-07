#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> next;

    void buildNext(string goal)
    {
        next.resize(goal.length(), 0);
        int i = 0, j = 1;
        while (j < goal.size())
        {
            while (i && goal[i] != goal[j])
            {
                i = next[i - 1];
            }
            //注意j必须放外面
            if (goal[i] == goal[j])
                next[j] = next[i] + 1;
            j++;
        }
    }

    bool kmp(string s, string goal)
    {
        int index = 0, temp = 0;
        while (temp < s.size() && index < goal.size())
        {
            if (s[temp] == goal[index])
            {
                index++;
                temp++;
            }
            else
            {
                if (index)
                    index = next[index - 1];
                else
                    temp++;
            }
        }
        return index == goal.size();
    }

    bool rotateString(string s, string goal)
    {
        buildNext(goal);
        return s.length() == goal.length() && kmp(s + s, goal);
    }
};

int main()
{
    Solution s;
    string s1 = "abcde", s2 = "abced";
    s.rotateString(s1, s2);
}