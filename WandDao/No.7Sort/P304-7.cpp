#include <iostream>
using namespace std;

enum color
{
    red,
    white,
    blue
} void
CreateFlat(int a[], int n)
{
    //low之前为红 low之后为蓝
    int low = 1, high = n, index = 1;
    while (index <= high)
    {
        switch (a[index])
        {
        case red:
            swap(a[low++],a[index++]);
            break;
        case blue:
            swap(a[high--],a[index]);
            break;
        case white:
        default:
            index++;
            break;
        }
    }
}