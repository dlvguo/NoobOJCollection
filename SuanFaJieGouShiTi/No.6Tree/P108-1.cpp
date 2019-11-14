#include<iostream>
#include"../../Headers/BinaryTree.h"
using namespace std;
//计算WPL的算法 第一层为0 第二层为1

//初始化为0
int FigureWpl(BiTree bt,int hight=1){
    if(!bt)
        return 0;
    return (hight-1)*bt->data+FigureWpl(bt->lchild,hight+1)+FigureWpl(bt->rchild,hight+1);
}