#include <iostream>
using namespace std;

int main()
{
    string str;
    int sum = 0;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'E' && str[i + 1] == 'N')
            {
                if (sum % 2)
                {
                    cout << 'B';
                }
                else
                {
                    cout << 'W';
                }
                cout << ' ' << sum << endl;
                sum = 0;
                break;
            }
            else if (str[i] >= '0' && str[i] <= '9' && str[i - 1] >= 'A')
                sum++;
        }
    }
}