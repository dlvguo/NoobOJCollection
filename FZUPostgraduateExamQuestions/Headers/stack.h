#include <iostream>
using namespace std;

#pragma region 链表栈
//链节点
typedef struct stacknode
{
    int data;
    stacknode *next;
} * linknode;

//链表栈
typedef struct linkstack
{
    linknode top;
} * Lstack;

//初始化链栈
void InitLstack(Lstack &L)
{
    L = new linkstack;
    L->top = NULL;
}

//判断栈为空
bool LStackEmpty(Lstack L)
{
    return L->top == NULL;
}

//放入
void PushL(Lstack L, int x)
{
    linknode l = new stacknode;
    l->data = x;
    l->next = L->top;
    L->top = l;
}

//出栈
void PopL(Lstack L)
{
    if (!L->top)
        return;
    linknode p = L->top;
    L->top = L->top->next;
    delete p;
}

//获取栈顶元素
int GetPopL(Lstack L)
{
    return L->top->data;
}
#pragma endregion

#pragma region 顺序栈
//默认栈底为-1 top表示初始值
typedef struct arrstack
{
    int top;
    int *data;
    int maxsize;
} * AStack;

//初始化顺序栈
void InitAStack(AStack &AL, int n)
{
    AL = new arrstack;
    AL->data = new int[n];
    AL->maxsize = n;
    AL->top = -1;
}

//放入元素
void PushA(AStack AL, int x)
{
    if (AL->maxsize == AL->top + 1)
        return;
    AL->data[++AL->top] = x;
}

//获取栈顶元素
int GetPopA(AStack A)
{
    if (A->top == -1)
        exit(1);
    return A->data[A->top];
}

//出栈
void PopA(AStack A)
{
    if (A->top == -1)
        exit(1);
    A->top--;
}
#pragma endregion
