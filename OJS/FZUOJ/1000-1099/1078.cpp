#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str, mod = "10011";
    int k;

    cin >> k;
    while (k--)
    {
        cin >> str;
        str += "0000";
        //模拟异或即可
        for (int i = 0; i < str.size() - 4; i++)
        {
            //o可忽略
            if (str[i] == '0')
                continue;
            for (int j = 0; j < 5; j++)
            {
                if (str[i + j] ^ mod[j])
                    str[i + j] = '1';
                else
                    str[i + j] = '0';
            }
        }
        for (int i = str.size() - 5; i < str.size(); i++)
        {
            cout << str[i];
        }
        cout << endl;
    }
}