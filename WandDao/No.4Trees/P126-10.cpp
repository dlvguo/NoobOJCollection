#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

#define K 100
//初始为1
int data=0;
void FindKNum(BiTree bt,int n)
{
    if(n==K){
        data=bt->data;
        return ;
    }
    if(n>K)
        return;
    FindKNum(bt->lchild,n+1);
    FindKNum(bt->rchild,n+1);
}