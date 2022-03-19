#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> price(n , 0), discount(n , 0);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> discount[i];
    }
    int m;
    cin >> m;
    vector<int> cprice(m , 0), dprice(m , 0);
    for (int i = 0; i < m; i++)
    {
        cin >> cprice[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> dprice[i];
    }
    string res = "";
    int ans = 0, dans = 0, desIndex = 0;
    for (int i = 0; i < price.size(); i++)
    {
        ans += price[i];
        dans += discount[i];
        int temp = ans;
        while (desIndex < cprice.size() && ans >= cprice[desIndex])
        {
            desIndex++;
        }
        if (desIndex - 1 >= 0 && ans >= cprice[desIndex - 1])
            temp -= dprice[desIndex - 1];
        if (dans > temp)
        {
            res.push_back('M');
        }
        else if (dans < temp)
        {
            res.push_back('Z');
        }
        else
            res.push_back('B');
    }
    cout << res << endl;
}