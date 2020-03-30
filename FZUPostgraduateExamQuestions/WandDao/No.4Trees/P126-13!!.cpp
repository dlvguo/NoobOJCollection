#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

//王道出栈法 找到直接返回即可
typedef struct Stack
{
    BiTree bt;
    //0表示左子树 1右子树访问
    int tag;
};
//假设P在q右边  按照后序遍历 则肯定先访问到P 之后才访问q

BiTree FindAncestor(BiTree root, BiTree p, BiTree q)
{
    //假设栈足够大 s1作为辅助栈 当找到p的时候 s1存p的祖先
    //再找到q节点，从栈顶依次出去 碰见第一个相同的即为公共祖先
    Stack s[], s1[];
    int top = -1, top1 = -1;
    BiTree pt = root;
    //肯定能找到P
    while (pt || top != -1)
    {
        Stack sp;
        while (pt && pt != p && pt != q)
        {
            sp.bt = pt;
            sp.tag = 0;
            s[++top] = sp;
            pt = pt->lchild;
            //然后判断
            if (pt == p)
            {
                top1 = top;
                for (int i = 0; i < top; i++)
                {
                    //辅助栈
                    s1[i] = s[i];
                }
            }
            //找到p节点
            else if (pt == q)
            {
                //从后面往前找相同的
                for (int i = top1; i >= 0; i++)
                {
                    for (int j = top; j >= 0; i++)
                    {
                        //如果找到
                        if (s1[i].bt == s[j].bt)
                            return s1[i].bt;
                    }
                }
                return NULL;
            }
        }
        //找到最上未访问节点
        while (top != -1 && s[top].tag == 1 &&)
        {
            top--;
        }
        //继续遍历 但是不为空
        if (top != -1)
        {
            s[top].tag = 1;
            p = p->rchild;
        }
    }
    return NULL;
}