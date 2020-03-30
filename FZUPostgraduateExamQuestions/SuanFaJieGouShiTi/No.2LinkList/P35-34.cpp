#include <iostream>
using namespace std;

typedef struct node
{
    node *next;
    char data;
} * LinkList;

void Divide(LinkList &A, LinkList &B, LinkList &C, LinkList &D)
{
    //设bcd为初始化好的头节点 b数字 c字母 d其他字符 rb、rc、rd为bcd末尾
    LinkList rb = B, rc = C, rd = D, pa = A->next;
    while (pa)
    {
        if (pa->data >= '0' && pa->data <= '9')
        {
            rb->next = pa;
            pa = pa->next;
            rb = rb->next;
            rb->next = NULL;
        }
        else if (pa->data >= 'a' && pa->data <= 'z' || pa->data <= 'Z' && pa->data >= 'A')
        {
            rc->next = pa;
            pa = pa->next;
            rc = rc->next;
            rc->next = NULL;
        }
        else
        {
            rd->next = pa;
            pa = pa->next;
            rd = rd->next;
            rd->next = NULL;
        }
    }
}