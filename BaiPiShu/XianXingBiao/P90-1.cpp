#include <iostream>
using namespace std;

void reverse(int a[], int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        a[low] ^= a[high] ^= a[low] ^= a[high];
        low++;
        high--;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i];
    }
    
}

int main()
{
    int a[]={1,2,3,4,5,6,7};
    reverse(a,7);
    return 0;
}