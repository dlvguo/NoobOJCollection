#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    node *prior;
} * Linklist;

//首先用一个双向链表L放好排序的内容,H和R分别未头节点和尾节点
//从Pi尾部开始向前依次比较 若找到一个pk胜pi则将pi放入 否则将pi插入头节点中
// a[i][j]表示选手Pi与Pj之间的胜负 为1 表示i战胜j 为0表示i输给j
void CountSort(int a[][], int len)
{
    //初始化
    Linklist L = new node, head, rear;
    L->data = a[1];
    L->prior = NULL;
    rear = head = L;
    for (int i = 2; i <= n; i++)
    {
        rear = L;
        Linklist p = rear->prior;
        //待插入节点I
        Linklist newnode = new node;
        newnode->data = i;
        //往链表前寻找
        while (p)
        {
            if (a[p->data][i]==1)
            {
                //表面pk战胜pi 将pi放入在pk后面
                rear->prior = newnode;
                newnode->prior = p;
                break;
            }
            //没有的继续往前探寻
            rear = p;
            p = p->prior;
        }
        //表明没有战胜pi的 将pi插入头节点
        if (p == NULL)
        {
            head->prior=newnode;
            newnode->prior=NULL;
        }
    }
}