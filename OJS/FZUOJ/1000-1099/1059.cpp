#include <iostream>
#include <string>
using namespace std;

int main()
{

    char str[55];
    while (gets(str))
    {
        int index = 0;
        while (str[index] != '\0')
        {
            if (str[index] >= 'A' && str[index] <= 'Z')
            {
                str[index] += 32;
            }
            index++;
        }
        cout << str << endl;
    }
}