#include <iostream>
#include"../../Headers/BinaryTree.h"
using namespace std;

int FigureHeight(BiTree bt,int key,int height=1){
    if(!bt)
        return 0;
    if(bt->data==key)
        return height;
    else if(bt->data>key)
        return FigureHeight(bt->lchild,key,height+1);
    return FigureHeight(bt->rchild,key,height+1);
}