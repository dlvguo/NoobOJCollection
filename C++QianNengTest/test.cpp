#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

int init(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(int));
    return 0;
}

void PrintBin(int n)
{
    if (n / 2)
    {
        PrintBin(n/2);
    }
    cout<<n%2;
}

int main()
{
    int maxsize = 15;
    PrintBin(11);
    cout<<endl;
    PrintBin(10);
    cout<<endl;
    int c = 11 & 10;
    printf("%d", c);
}