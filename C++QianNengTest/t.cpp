#include <iostream>
using namespace std;
int main()
{
    int p[2][4] = {12, 36, 62, 14, 56, 98, 74, 63};
    int i, j;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 4; j++)
        {
            cout << *(*(p + i) + j) << "   ";
        }        cout << endl;
    }
        for (i = 0; i < 20; i++)
        {
            cout << '-';
        }
        cout << endl;
        for (i = 0; i < 2; i++)
        {
            for (j = 3; j >= 0; j--)
            {
                cout << p[i][j] << "   ";
            }
            cout << endl;
        }
    }
