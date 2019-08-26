#include <iostream>
using namespace std;

int AscAB(int a[],int n,int s,int l)
{
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>=s&&a[i]<=l){
            count++;
        }
        else
        {
            a[i-count]=a[i];
        }
    }
    return n-count;
}

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int count=AscAB(a,10,2,9);
    for (int i = 0; i < count; i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}