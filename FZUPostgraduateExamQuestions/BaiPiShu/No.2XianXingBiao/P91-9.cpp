#include <iostream>
using namespace std;

void PrintAsc(int a[], int b[], int al, int bl)
{
    int al1 = 0, bl1 = 0, temp;
    if (a[0] < b[0])
    {
        al1++;
        temp = a[0];
    }
    else
    {
        bl1++;
        temp = b[0];
    }
    cout << temp;
    while (al1 < al && bl1 < bl)
    {
        if (a[al1] < b[bl1])
        {
            if (a[al1] != temp)
            {
                temp = a[al1];
                cout << temp;
            }
            al1++;
        }
        else
        {
            if (b[bl1] != temp)
            {
                temp = b[bl1];
                cout << temp;
            }
            bl1++;
        }
    }
    while (al1 < al)
    {
        if (a[al1] != temp)
        {
            temp = a[al1];
            cout << temp;
        }
        al1++;
    }
    while (bl1 < bl)
    {
        if (b[bl1] != temp)
        {
            temp = b[bl1];
            cout << temp;
        }
        bl1++;
    }
}

int main()
{
    int a[100] = {1, 2, 3, 4, 6,7,7,7}, b[7] = {2, 4, 5, 6, 9};
    PrintAsc(a,b,8,5);
    return 0;
}