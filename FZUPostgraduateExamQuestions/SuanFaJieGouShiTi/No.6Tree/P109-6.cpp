#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

#define N 100

void Create(BiTree T[], BiTree L[], BiTree R[])
{
    for (int i = 1; i <= N; i++)
    {
        T[i]=NULL;
        for (int j = 1; 1 <= N; i++)
        {
            if (L[j]!=NULL&&L[j]->data == i)
            {
                T[i] = L[j];
                break;
            }
            if(R[j]!=NULL&&R[j]->data==[j]){
                T[i]=R[j];
                break;
            }
        }
    }
}

bool FindFather(BiTree u,BiTree v,BiTree T[]){
    //找u的祖先是否是v 一直看T[]这个即可
    BiTree point=u;
    while (T[point->data]&&T[point->data]!=v)
    {
        point=T[point->data];
    }
    if(T[point->data]==u)
        return true;
    return false;
}