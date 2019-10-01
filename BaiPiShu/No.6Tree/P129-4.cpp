#include <iostream>
#include <stack>
#include "../../Headers/BinaryTree.h"
using namespace std;

//兄弟表示法算深度DFS
int heightdfs(BiTree bt)
{
    if (!bt)
        return 0;
    int lweight = 1 + heightdfs(bt->lchild);
    int rweight = heightdfs(right);
    return lweight > rweight ? lweight : rweight;
}

//!有点问题兄弟表示法非递归
int height(BiTree bt)
{
    int maxheight = 0;
    int nowheight = 0;
    stack<BiTree> btstack;
    BiTree p = bt,rear=NULL;
    //采用后序遍历
    while (p || !btstack.empty())
    {
        if (p)
        {
            btstack.push(p);
            p = p->lchild;
            nowheight++;
            if (nowheight > maxheight)
            {
                maxheight = nowheight;
            }
        }
        else{
            nowheight--;
            //获取栈顶指针
            p=btstack.top();
            //代表又指针访问过了 出栈
            if(p->rchild==rear){
                btstack.pop();
                rear=p;
                p=NULL;
            }
            else{
                p=p->rchild;
            }
        }
    }
}

int main()
{
}