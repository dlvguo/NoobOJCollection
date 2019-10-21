#include <iostream>
using namespace std;

int QuickSearch(int a[], int len, int key)
{
    int low = 1, high = len;
    while (low < high)
    {
        while (low < high && a[high] > key)
        {
            high--;
        }
        if (low <= high && a[high] == key)
            return high;
        while (low < high && a[low] < key)
        {
            low++;
        }
        if (low <= high && a[low] == key)
            return low;
    }
    printf("NotFound");
    return 0;
}