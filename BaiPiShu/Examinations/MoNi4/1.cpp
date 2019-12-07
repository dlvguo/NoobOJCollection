#include <iostream>
#include <algorithm>
using namespace std;

int cmp(const int a, const int b)
{
    return a > b ?
}

int Figuer(int candy[], int kid[], int n,int m)
{
    //从到大排列即可
    qsort(candy, n, sizeof(int), cmp);
    qsort(kid, m, sizeof(int), cmp);
    int sum = 0;
    int candyIndex=1,kidIndex=1;
    while (candyIndex<=n&&kidIndex<=m)
    {
        if(candy[candyIndex]>=kid[kidIndex]){
            sum++;
            candyIndex++;
            kidIndex++;
        }
        else
        {
            candyIndex++;
        }
    }    
    return sum;
}