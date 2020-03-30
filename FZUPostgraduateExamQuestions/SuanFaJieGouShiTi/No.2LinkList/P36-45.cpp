#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

//其实就是一个最大匹配问题 公共子序列
void Search(LinkList &a, LinkList &b)
{
    //假设只存在一个序列 p表示a中的末尾 s表示b中的末尾
    LinkList pre = a, p = a->next, s = b->next;
    while (pre && p && s)
    {
        if (p->data == s->data)
        {
            p = p->data;
            s = s->data;
        }
        else
        {
            pre = pre->next;
            p = pre->next;
            s = b->next;
        }
    }
    if (s != NULL)
        return;
    //此时p为最末节点 只需要将b节点内容以头插法插入pre下即可
    //简单的说法做个栈 在不改变原来的情况下改变数组
    char stack[], top = -1;
    s = b->next;
    while (s)
    {
        stack[++top] = s->data;
        s = s->next;
    }
    p=pre->next;
    while (top != -1)
    {
        p->data=stack[top--];
        p=p->next;
    }
}