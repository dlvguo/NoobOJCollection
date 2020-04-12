#include <iostream>
using namespace std;

int sum;

//dfs遍历注意边界
void dfs(int l, int right, string &s, int index)
{
    if (index > s.size() || right > l || l > s.size() / 2)
        return;
    if (index == s.size() && l == right)
    {
        sum++;
        return;
    }
    if (s[index] == '(')
    {
        dfs(l + 1, right, s, index + 1);
    }
    else if (s[index] == ')')
    {
        dfs(l, right + 1, s, index + 1);
    }
    else
    {
        dfs(l + 1, right, s, index + 1);
        dfs(l, right + 1, s, index + 1);
    }
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        sum = 0;
        dfs(0, 0, s, 0);
        cout << sum << endl;
    }
}