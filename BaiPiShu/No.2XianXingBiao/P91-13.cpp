#include <iostream>
#include "../../Headers/linkList.h"
#include "../../Headers/array.h"

using namespace std;

LinkList AscLink(LinkList A, LinkList B)
{
    LinkList C = NULL;
    Node *pr;
    if (A->data < B->data)
    {
        C = A;
        A = A->next;
    }
    else
    {
        C = B;
        B = B->next;
    }
    pr = C;

    while (A && B)
    {
        if (A->data > B->data)
        {
            pr->next = B;
            B = B->next;
        }
        else
        {
            pr->next = A;
            A = A->next;
        }
        pr = pr->next;
    }
    while (A)
    {
        pr->next = A;
        pr = pr->next;
        A = A->next;
    }
    while (B)
    {
        pr->next = B;
        pr = pr->next;
        B = B->next;
    }
    return C;
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-13.txt", "r", stdin);
    LinkList A, B, C;
    int *a = CreatyIntArr(5), *b = CreatyIntArr(3);
    InitList(A, a, 5, false);
    InitList(B, b, 3, false);
    C = AscLink(A, B);
    PrintList(C, false);
    return 0;
}

