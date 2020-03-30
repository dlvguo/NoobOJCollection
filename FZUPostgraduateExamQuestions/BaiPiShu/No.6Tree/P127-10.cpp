#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//设空树为0
bool TreeSimilar(BiTree a, BiTree b)
{
    if(a==b){
        //如果不为空
             return TreeSimilar(a->lchild,b->lchild)&&TreeSimilar(a->rchild,b->rchild);
        }
        return true;
    }
    return false;
}

int main()
{
}