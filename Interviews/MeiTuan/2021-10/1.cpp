#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    map<int, int> sMap;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sMap[temp]++;
    }
    int res = 0;
    bool tag = false;
    for (auto s : sMap)
    {
        res += s.second;
        if (res >= x)
        {
            if (res > y)
            {
                cout << -1 << endl;
                tag = true;
                break;
            }
            else
            {
                int num = n - res;
                if (num >= x && num <= y)
                {
                    cout<<s.first<<endl;
                    tag=true;
                    break;
                }
            }
        }
    }
    if (!tag)
        cout << -1 << endl;
}