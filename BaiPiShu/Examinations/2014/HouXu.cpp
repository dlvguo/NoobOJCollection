#include<iostream>
using namespace std;

typedef struct TreeNode{
    TreeNode *lchild,*rchild;
    int data,lthread,rthread;
}*ThreadTree;

//后序的前后继查找

//前继看右如果有孩子就是 否则就是左边第一个 无论有否
ThreadTree Prior(ThreadTree bt){
    if(!bt)
        return NULL;
    if(bt->rthread)
        return bt->rchild;
    return bt->lchild;
}

//后继 
ThreadTree Next(ThreadTree bt,ThreadTree x){
    //如果为1 
    if(x->rthread==1)
        return x->rchild;
    //因为是在上方 故只能从bt开始找 当某点的前继为x则说明这个为x的后继
    ThreadTree p=bt,pprior=Prior(p);
    while (pprior!=x)
    {
        p=pprior;
        pprior=Prior(p);
    }
    return p;
}
