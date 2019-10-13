#include <iostream>
#include"../../Headers/BinaryTree.h"
using namespace std;

bool JudgeBalance(BiTree a,BiTree b){
    //ab不相等
    if(a!=b)
        return false;
    //ab为空
    if(a==NULL)
        return true;
    return JudgeBalance(a->lchild,b->lchild)&&JudgeBalance(a->rchild,b->rchild);
}