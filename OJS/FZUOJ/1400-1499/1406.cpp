#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {

                int t = str[i] - 'a';
                t -= 3;
                if (t < 0)
                    t += 26;
                str[i] = t + 'a';
                continue;
            }
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                int t = str[i] - 'A';
                t -= 3;
                if (t < 0)
                    t += 26;
                str[i] = t + 'A';
            }
        }
        cout << str << endl;
    }
}