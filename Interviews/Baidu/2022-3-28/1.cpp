#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string &s1, const string &s2)
{
    if (s1.size() == s2.size())
        return s1 > s2;
    return s1.size() > s2.size();
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> vts;
    for (int i = 1; i <= k; i++)
    {
        int num = i * n;
        string str = to_string(num);
        while (str.size() && str.back() == '0')
        {
            str.pop_back();
        }
        reverse(str.begin(), str.end());
        vts.push_back(str);
    }
    sort(vts.begin(), vts.end(), cmp);
    cout << vts[0] << endl;
}