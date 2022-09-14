#include <bits/stdc++.h>
using namespace std;

// 先按长度来
bool cmp(const string &s1, const string &s2)
{
    if (s1.size() == s2.size())
        return s1 > s2;
    return s1.size() > s2.size();
}

bool cmp2(const string &s1, const string &s2)
{
    return s1 > s2;
}

int main()
{
    int n;
    cin >> n;
    vector<string> vts;
    while (n--)
    {
        int temp;
        cin >> temp;
        vts.push_back(to_string(temp));
    }

    sort(vts.begin(), vts.end(), cmp);

    if (vts.size() == 1)
    {
        cout << vts[0] << endl;
    }
    else if (vts.size() == 2)
    {
        string s1 = vts[0] + vts[1];
        string s2 = vts[1] = vts[2];
        if (s1 < s2)
        {
            cout << s2 << endl;
        }
        else
        {
            cout << s1 << endl;
        }
    }
    else
    {
        vector<string> vtstemp;
        vtstemp.push_back(vts[0]);
        vtstemp.push_back(vts[1]);
        vtstemp.push_back(vts[2]);
        sort(vtstemp.begin(), vtstemp.end(), cmp2);
        cout << vtstemp[0] + vtstemp[1] + vtstemp[2] << endl;
    }
}