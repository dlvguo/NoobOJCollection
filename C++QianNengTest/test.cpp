#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int ** test(int **p)
{
    **p = 15;
    return p;
}

int main()
{
    int p = 10;
    int *q = &p;
    int **tt = test(&q);
    cout<<**tt;
}