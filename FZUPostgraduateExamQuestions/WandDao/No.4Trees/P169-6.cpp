#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//判断高度 用一个2表示检测到高度差错误
bool Judge(BiTree bt)
{
    if(!bt)
        return true;
    if(bt->lchild&&bt->data<=bt->lchild->data){
        return false;
    }
    if(bt->rchild&&bt->data>=bt->rchild->data){
        return false;
    }
    return Judge(bt->lchild)&&Judge(bt->rchild);
}

int main()
{
}