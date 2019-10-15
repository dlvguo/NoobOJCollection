#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//二叉树根节点所
bool Judge(int path[], int start, int end, BiTree bt)
{
    //如果b为空的
    if (bt == NULL)
        //判定是否相邻
        return start - end == 1;
    int i = start;
    while (i <= end)
    {
        if (path[i] == bt->data)
            break;
        i++;
    }
    //序列中不存在树的值
    if (i > end)
        return false;
    //若存在去左右子树中查找
    return Judge(path, start, i - 1, bt->lchild) && Judge(path, i + 1, end, bt->rchild);
}

//法二计算出二叉树前序的路径与之对比
//全局变量代表中序访问到第几个节点
int k;
int len; //代表序列长度
bool Judge(BiTree bt, int path[])
{
    if (k > len)
        return false;
    if (!bt)
    {
        //如果为空的话暂时先返回true
        return true;
    }
    //如果左子树序列不同
    if (!Judge(bt->lchild, path))
        return false;
    k++;
    //根节点的序列相同 则看右子树 否则返回false
    if (path[k] == bt->data)
        return Judge(bt->rchild, path);
    return false;
}