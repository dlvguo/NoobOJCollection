#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseParentheses(string s)
    {
        vector<int> popCountV;
        string str;
        string temps = s;
        int left = 0, right = 0;
        //找到括号内的 进行反转 优化部分估计得计算括号数量
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                left++;
                popCountV.push_back(i - left - right);
            }
            else if (s[i] == ')')
            {
                int num = left + right;
                reverse(str.begin() + popCountV.back() + 1, str.begin() + i - num);
                popCountV.pop_back();
                right++;
            }
            else
            {
                str.push_back(s[i]);
            }
        }
        return str;
    }
};

int main()
{
    string s = "a(bcdefghijkl(mno)p)q";
    Solution s1;
    cout << s1.reverseParentheses(s);
    system("pause");
}