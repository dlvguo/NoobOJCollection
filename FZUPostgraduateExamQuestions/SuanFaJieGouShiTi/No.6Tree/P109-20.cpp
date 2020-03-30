#include<iostream>
#include"../../Headers/BinaryTree.h"
using namespace std;

BiTree path[];
int top=-1;
void Dfs(BiTree bt){
    if(bt){
        //如果为叶节点输出
        if(bt->lchild==NULL&&bt->rchild==NULL){
            for(int  i=0;i<=top;i++)
                cout<<path[i]->data;
            cout<<bt->data<<endl;
        }
        //如果不是的话当前节点入栈
        else{
            path[++top]=bt;
            Dfs(bt->lchild);
            Dfs(bt->rchild);
            //回溯出栈
            --top;
        }
    }
}
