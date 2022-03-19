#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int n, t;
    cin >> n >> t;
    cin >> str;
    string res = "";
    int l, r;
    if (t == 1)
    {
        if (n % 2)
        {
            res.push_back(str[n / 2]);
            l = n / 2 - 1;
            r = n / 2 + 1;
        }
        else
        {
            l = n / 2 - 1;
            r = n / 2;
        }
        while (l >= 0 && r < str.size())
        {
            res.push_back(str[l--]);
            res.push_back(str[r++]);
        }
    }
    else
    {
        res.resize(str.size()+1);
        l = 0;
        r = res.size()-2;
        // 为true右边加 false左边加
        bool tag = true;
        for (int i = str.size()-1; i >= 0; i--)
        {
            if (tag)
            {
                res[r--] = str[i];
                tag = !tag;
            }
            else
            {
                res[l++] = str[i];
                tag = !tag;
            }
        }
    }
    res.pop_back();
    cout << res << endl;
}