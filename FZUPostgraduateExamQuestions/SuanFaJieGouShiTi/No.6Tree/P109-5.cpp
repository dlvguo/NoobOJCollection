#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;
//求出三个点

//顺序结构的话 非完全二叉树按序列来看即可
int Figure(BiTree trees[],int h)
{
    //高度h的总长度
    int lenth=1,count=0;
    for (int i = 1; i <=h; i++)
    {
        lenth*=2;
    }
    lenth--;
    //在(1-n/2)-1下标中需要判断是否有孩子为空
    for (int i = 0; i <=lenth/2-1; i++)
    {
        if(trees[2*i]==NULL&&trees[2*i+1]==NULL)
            count++;
    }
    //在n/2+1下标中只需要判断是否为空 不为空就是叶节点
    for (int i = n/2+1; i< lenth; i++)
    {
        if(trees[i]==NULL)
            count++;
    }
    return count;
}