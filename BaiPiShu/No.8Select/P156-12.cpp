#include <iostream>
using namespace std;
typedef struct binode{
    binode *lchild,*rchild;
    int balance;
    int data;
}*Bitree;

int FigureHeight(Bitree bt){
    if(bt==0)
        return 0;
    //假设右子树高或者一样高
    if(bt->balance>=0)
        return FigureHeight(bt->rchild)+1;
    //假设左子树高
        return FigureHeight(bt->rchild)+1;
}