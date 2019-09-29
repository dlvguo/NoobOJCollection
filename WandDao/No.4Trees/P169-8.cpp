#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//判断高度 用一个2表示检测到高度差错误
//我平衡及孩子平衡
int Judge(BiTree bt)
{
    if (bt == NULL)
        return 0;
    int lh=Judge(bt->lchild),rh=(bt->rchild);
    //防止多出
    if(lh>1||lh<-1||rh>1||rh<-1)
        return -2;
    return lh-rh;
}

int main()
{
}