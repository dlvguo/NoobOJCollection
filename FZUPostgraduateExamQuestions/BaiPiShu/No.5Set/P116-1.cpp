#include <iostream>
#include "../../Headers/array.h"
using namespace std;
#define MAX 11
typedef int SetItem;
//代表每个链表中的节点
typedef struct lnode
{
    lnode *next;
    SetItem item;
} * Lnode;
//每个链地址
typedef struct link
{
    Lnode first;
} * Link, *HTK[MAX];

void Insert(HTK htk, int key[])
{
    //获取关键字长度
    int len = sizeof(key);
    //初始化HTK
    for (int i = 0; i < MAX; i++){
        htk[i]=new link;
        htk[i]->first = 0;
        }
    for (int i = 0; i < len; i++)
    {
        int index = key[i] % MAX;
        //表明第一个指针为空做头节点
        if (!htk[index]->first)
        {
            Lnode newnode = new lnode;
            newnode->item = key[i];
            newnode->next = 0;
            htk[index]->first = newnode;
        }
        else
        {
            Lnode p = htk[index]->first;
            while (p->next)
            {
                p=p->next;
            }
            Lnode newnode = new lnode;
            newnode->item = key[i];
            newnode->next = 0;
            p->next=newnode;
        }
    }
}

void FigureASL(HTK htk){
    int totalNum=0,searchNum=0;
    for (int i = 0; i < MAX;i++)
    {
        Lnode p=htk[i]->first;
        int index=0;
        while (p)
        {
            index++;
            totalNum++;
            searchNum+=index;
            p=p->next;
        }
    }
    cout<<searchNum<<":"<<totalNum;
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/No.5Set/P116-1.txt", "r", stdin);
    int *a=CreatyIntArr(9);
    HTK htk;
    Insert(htk,a);
    FigureASL(htk);

}