#include <iostream>
#include <vector>
using namespace std;

void Figure(int n)
{
    vector<vector<int>> vts;
    vector<int> v1(1, 0);
    vts.push_back(v1);
    v1[0] = 1;
    vts.push_back(v1);
    vts.push_back(v1);

    for (int i = 3; i <= n; i++)
    {
        vector<int> v;
        int dig = 0;
        for (int j = 0; j < vts[i - 2].size(); j++)
        {
            int temp = vts[i - 1][j] + vts[i - 2][j] + dig;
            v.push_back(temp % 10);
            dig = temp / 10;
        }
        for (int j = vts[i - 2].size(); j < vts[i - 1].size(); j++)
        {
            int temp = vts[i - 1][j] + dig;
            v.push_back(temp % 10);
            dig = temp / 10;
        }
        if (dig)
            v.push_back(1);
        vts.push_back(v);
    }
    for (int i = vts[n].size() - 1; i >= 0; i--)
    {
        printf("%d", vts[n][i]);
    }
    cout << endl;
}

int main()
{
    int n;
    while (cin >> n)
    {
        Figure(n);
    }
}