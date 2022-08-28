#include <bits/stdc++.h>
using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S)
{
    int res = 0;

    unordered_map<int, int> curMap;
    curMap[0] = 0;
    int cur = 0;

    for (int i = 0; i < S.size(); i++)
    {
        cur ^= (1 << (S[i] - 'a'));
        if (curMap.find(cur) == curMap.end())
        {
            curMap[cur] = i;
        }
        else
        {
            int temp = i - curMap[cur] + 1;
            if (temp & 1)
                temp--;
            res = max(temp, res);
        }
    }
    return res;
}

int main()
{
    string str = "bdaaadacb";
    cout << solution(str);
}
