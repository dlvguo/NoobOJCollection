#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    set<string> _set;
    set<string>::iterator iter;
    while (cin >> n)
    {
        _set.clear();
        int sum = 0;
        string str;
        while (n--)
        {
            cin >> str;
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] >= 'a')
                    str[i] -= 32;
            }

            iter = _set.find(str);

            if (iter == _set.end())
            {
                sum++;
                _set.insert(str);
            }
        }
        cout << sum << endl;
    }
}