#include <iostream>
#include "../../Headers/BinaryTree.h"
using namespace std;

//创建哈夫曼树 国哥法
BiTree CreateHafuman(BiTree w[], int len)
{
    //用于记录某个权值的数是否使用
    int wtag = new int[len];
    for (int i = 0; i < 2 * len; i++)
    {
        wtag[i] = 0;
    }
    //按权值从小到大排列
    for (int i = 0; i < len - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (w[i]->data > w[j]->data)
            {
                index = j;
            }
        }
        if (index != i)
        {
            BiTree temp = w[index];
            w[index] = w[i];
            w[i] = temp;
        }
    }

    int count = 0;
    BiTree head;
    //代表原数组下标
    while (count ！ = len - 1)
    {
        //始终把最小的俩权值放在1、2个位置
        BiTree bt = w[0];
        BiTree bt1 = w[1];
        BiTree newnode = new BiTNode;
        newnode->data = bt->data + bt1->data;
        newnode->lchild = bt;
        newnode->rchild = bt1;
        count++;
        //若未找到新节点移动俩步
        int removestep = 2;
        //移动位置,并按从小到大位置插入
        for (int i = 2; i < len - count; i++)
        {
            //如果新节点未插入
            if (removestep == 2)
            {
                //找到新节点步长变为1
                if (newnode->data <= w[i])
                {
                    w[i - 2] = newnode;
                    w[i - 1] = w[i];
                    removestep = 1;
                }
            }
            w[i - removestep] = w[i];
        }
        head = newnode;
    }
    return head;
}

#define N 100

//使用数组表示法
typedef struct hfmannode
{
    int weight;
    int parent;
    int lchild, right;
} HfmTree[2 * N]; //1-2N-1下标表示哈夫曼总数

HfmTree Create(int w[])
{
    HfmTree hf;
    for (int i = 1; i < 2*N; i++)
    {
        //初始化
        hf[i].parent=-1;
        if(i<=n){
            hf[i].weight[w[i]];
        }
    }
    int nodenums=n;
    //若 nodenums==2*N表示树已生成
    while (nodenums<2*N)
    {
        //取出最小的俩个节点生成新的节点 
        int min,secondmin,minindex,secondindex;
        minindex=secondindex=-1;
        min=secondmin=-1;
        for (int i = 1; i <= nodenums; i++)
        {
            //表示已经存在
            if(hf[i].parent!=-1)
                continue;
            //寻找第一个点
            if(minindex==-1){
                min=hf[i].weight;
                minindex=i;
            }
            else if(min>=hf[i].weight) {
                secondmin=min;
                secondindex=minindex;
                min=hf[i].weight;
                minindex=i;
            }
        }
        nodenums++;
        hf[minindex].parent=hf[secondindex]=nodenums;
        hf[nodenums].weight= hf[minindex].weight+hf[secondindex].weight;
        hf[nodenums].lchild=minindex;
        hf[nodenums].right=secondindex;
    }
    //此时最后一个节点为根节点
    return hf;
}