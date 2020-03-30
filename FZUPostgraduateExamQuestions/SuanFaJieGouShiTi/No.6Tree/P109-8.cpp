#include<iostream>
#include"../../Headers/BinaryTree.h"
using namespace std;

BiTree CreateBin(BiTree A[],int n){
    for (int i = 1; i <=n/2; i++)
    {
        A[i]->lchild=A[2*i];
        if(2*i+1<=n){
            A[i]->rchild=A[2*i+1];
        }
    }
    for (int i = n/2+1; i <=n; i++)
    {
        A[i]->lchild=A[i]->rchild=NULL;
    }
    return A[1];
}
