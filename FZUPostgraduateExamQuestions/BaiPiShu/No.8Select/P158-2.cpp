#include <iostream>
using namespace std;

typedef struct node
{
    node *next;
    double data;
} * Linklst;

#define K 999
Linklst Set[K];

//二元组结构体
struct couple
{
    int index;
    double *data;
    int len;
}

//插入 O(1)
void
Insert(couple c)
{
    Linklst list = Set[c.index];
    //头插法无需初始化
    for (int i = 0; i < c.len; i++)
    {
        node *p = new node;
        p->data = c.data[i];
        p->next = list;
        list = p;
    }
}

//O(V+N) V表示集合元素 N表示集合顶点数
int Search(double key)
{
    for (int i = 1; i < K; i++)
    {
        Linklst p = Set[i];
        while (p)
        {
            if (p->data == key)
                return i;
            p = p->next;
        }
    }
    return 0;
}