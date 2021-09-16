#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     bool checkValidString(string s)
//     {
//         stack<int> ls, xs;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == '(')
//             {
//                 ls.push(i);
//             }
//             else if (s[i] == '*')
//             {
//                 xs.push(i);
//             }
//             else
//             {
//                 if (ls.size())
//                 {
//                     ls.pop();
//                 }
//                 else if (xs.size())
//                     xs.pop();
//                 else
//                     return false;
//             }
//         }
//         while (ls.size() && xs.size() && ls.top() < xs.top())
//         {
//             ls.pop();
//             xs.pop();
//         }
//         return ls.empty();
//     }
// };

class Solution
{
public:
    bool checkValidString(string s)
    {
        int minc = 0, maxc = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                minc++;
                maxc++;
            }
            else if (s[i] == '*')
            {
                minc = minc ? minc - 1 : 0;
                maxc++;
            }
            else
            {
                minc = minc ? minc - 1 : 0;
                maxc--;
                if (maxc < 0)
                    return false;
            }
        }
        return minc == 0;
    }
};
