#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

vector<string> nums;
vector<string> strs;

void dfs(int len, string digits, string point = "")
{
    if (len == digits.length())
    {
        strs.push_back(point);
        return;
    }
    int index = digits[len] - '2';
    string k = nums[index];
    for (int i = 0; i < k.length(); i++)
    {
        point += k[i];
        dfs(len + 1, digits, point);
        point.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    nums.push_back("abc");
    nums.push_back("def");
    nums.push_back("ghi");
    nums.push_back("jkl");
    nums.push_back("mno");
    nums.push_back("pqrs");
    nums.push_back("tuv");
    nums.push_back("wxyz");
    if (digits.length() == 0)
        return strs;
    dfs(0, digits);
    return strs;
}
}
;
int main()
{
}