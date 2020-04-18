#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    int n;
    string str;
    cin >> n;
    getchar();
    while (n--)
    {
        string s;
        getline(cin, str);
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                if (s.size())
                {
                    if (s.size() > 2)
                    {
                        cout << s[0] << s[s.size() - 1];
                    }
                    else
                    {
                        cout << s;
                    }
                    s.clear();
                }
                cout << str[i];
            }
            else
            {
                s += str[i];
            }
        }
        if (s.size())
            if (s.size() > 2)
            {
                cout << s[0] << s[s.size() - 1];
            }
            else
            {
                cout << s;
            }
        printf("\n");
    }
}