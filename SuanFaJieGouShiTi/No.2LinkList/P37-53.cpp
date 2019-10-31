#include <iostream>
#include "../../Headers/linkList.h"
using namespace std;

void Print(LinkList p)
{
    if (!p)
        return;
    Print(p->next);
    cout << p->data;
}
