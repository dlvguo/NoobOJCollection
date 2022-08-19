#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    deque<char> sc;
    deque<long long> si;

    void figure()
    {

        int r = si.back();
        si.pop_back();
        int l = si.back();
        si.pop_back();

        switch (sc.back())
        {
        case '+':
            si.push_back(l + r);
            break;
        case '-':
            si.push_back(l - r);
            break;
        case '*':
            si.push_back(l * r);
            break;
        default:
            si.push_back(l / r);
            break;
        }
        sc.pop_back();
    }

    void figuref()
    {

        int l = si.front();
        si.pop_front();
        int r = si.front();
        si.pop_front();

        switch (sc.front())
        {
        case '+':
            si.push_front(l + r);
            break;
        case '-':
            si.push_front(l - r);
            break;
        case '*':
            si.push_front(l * r);
            break;
        default:
            si.push_front(l / r);
            break;
        }
        sc.pop_front();
    }

    int calculate(string s)
    {

        long long temp = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            if (s[i] >= '0' && s[i] <= '9')
            {
                temp = temp * 10 + s[i] - '0';
            }
            else
            {
                si.push_back(temp);
                temp = 0;
                if (sc.size() && (sc.back() == '*' || sc.back() == '/'))
                    figure();
                sc.push_back(s[i]);
            }
        }
        si.push_back(temp);
        if (sc.size() && (sc.back() == '*' || sc.back() == '/'))
            figure();

        while (si.size() > 1)
        {
            figuref();
        }

        return si.front();
    }
};