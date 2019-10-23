#include <iostream>
#include <cstring>
using namespace std;
void MaxHe(char *a)
{
    int low=0,high=strlen(a)-1;
    while (low<high)
    {
        char temp=a[low];
        a[low]=a[high];
        a[high]=temp;
        low++;
        high--;
    }
    cout<<a;
}

int main()
{
    char *a="WHATFUCKYOU";
    MaxHe(a);
}