#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#pragma region 王晓东二叉树
//元素类型
typedef int TreeItem;
//元素类型指针
typedef TreeItem *Treeaddr;
typedef struct btnode *btlink;
typedef struct btnode
{
    TreeItem data;
    //左右子树
    btlink lchild, rchild;
} * BtNode;
//创建新节点
btlink CreateNewNode()
{
    btlink bt = new btnode;
    return bt;
}

typedef struct binarytree
{
    //根节点
    BtNode root;
} * BTree;

//二叉树运算
BTree BinaryInit()
{
    BTree bt = new binarytree;
    bt->root = NULL;
    return bt;
}

//判断二叉树是否为空
int EmptyBtree(BTree bt)
{
    return bt->root == 0;
}

//返回树根元素
TreeItem Root(BTree bt)
{
    if (EmptyBtree(bt))
        exit(1);
    return bt->root->data;
}

//赋值根元素
void MakeTree(TreeItem x, BTree bt, BTree l, BTree r)
{
    bt->root = CreateNewNode();
    bt->root->data = x;
    bt->root->lchild = l->root;
    bt->root->rchild = r->root;
    //释放root
    l->root = r->root = 0;
}

//拆开二叉树
TreeItem BreakTree(BTree b, BTree l, BTree r)
{
    l->root = b->root->lchild;
    r->root = b->root->rchild;
    TreeItem item = b->root->data;
    b->root = 0;
    return item;
}
#pragma endregion

#pragma region 王道二叉树

typedef int ElementType;
//树结构定义
typedef struct BiTNode
{
    ElementType data;
    BiTNode *lchild, *rchild;
} * BiTree;

//预留接口
void visit(BiTree bt) {}

//二叉树前序
void PreOrder(BiTree bt)
{
    if (bt)
    {
        visit(bt);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

//二叉树中序
void InOrder(BiTree bt)
{
    if (bt)
    {
        InOrder(bt->lchild);
        visit(bt);
        InOrder(bt->rchild);
    }
}

//二叉树后序
void PostOrder(BiTree bt)
{
    if (bt)
    {
        visit(bt);
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
    }
}

#pragma region 借助栈辅助遍历

/*
简单来说就是看遍历的顺序 
前序：NLR 则先遍历N，之后要搜索L，就把R先放栈回溯
中序：LNR 则先遍历L的时候，把N放入栈
后续：LRN，则考虑先遍历L，按N放入栈然后R入栈，俩个tag 一个表示访问左子树一个右子树 只有俩个子树同时访问完才能出了N 

*/
//前序借助栈
void PreOrderByStack(BiTree bt)
{
    stack<BiTree> btstack;
    BiTree p = bt;
    while (p || !btstack.empty())
    {
        if (p)
        {
            visit(p);
            if (p->rchild)
                btstack.push(p->rchild);
            p = p->lchild;
        }
        else
        {
            p = btstack.top();
            btstack.pop();
        }
    }
}
//中序借助栈
void InOrderByStack(BiTree bt)
{
    stack<BiTree> btstack;
    BiTree p = bt;
    while (p || !btstack.empty())
    {
        if (p)
        {
            btstack.push(p);
            p = p->lchild;
        }
        else
        {
            p = btstack.top();
            btstack.pop();
            visit(p);
            p = p->rchild;
        }
    }
}

typedef struct pbitnode
{

    ElementType data;
    pbitnode *lchild, *rchild;
    //左右标记
    int ltag, rtag;
} * PBiTree;
//后续借助栈 左右tag 
void PostOrderByStack(PBiTree bt)
{
    stack<PBiTree> btstack;
    PBiTree p = bt;
    while (p || !btstack.empty())
    {
        if (p)
        {
            btstack.push(p);
            p = p->lchild;
            p->ltag = 1;
        }
        else
        {
            //获取但没栈顶元素出栈
            p = btstack.top();
            //代表俩个子树都访问了  感觉只要一个rtag就可以了
            if (p->ltag && p->rtag)
            {
                visit(p);
                //出栈
                btstack.pop();
                p = NULL;
                continue;
            }
            //代表访问右子树
            p->rtag = 1;
            p=p->rchild;
        }
    }
}

//层次遍历
void LevelOrder(BiTree bt)
{
    queue<BTree> bqueue;
    BiTree p;
    bqueue.push(bt);
    while (!bqueue.empty())
    {
        p = bqueue.front();
        bqueue.pop();
        visit(p);
        if (p->lchild)
            bqueue.push(p->lchild);
        if (p->rchild)
            bqueue.push(p->rchild);
    }
}
#pragma endregion
#pragma endregion
#pragma region 王道线索二叉树
typedef struct threadnode
{
    int ltag, rtag; //0表示子孩子 1表示前驱
    threadnode *lchild, *rchild;
} ThreadNode, *ThreadTree;

//中序线索二叉树 正常遍历即可 做一些细节处理
void InThread(ThreadTree bt, ThreadTree &pre)
{
    if (bt)
    {
        //先遍历左子树
        InThread(bt->lchild, pre);
        if (!bt->lchild)
        {
            //为空 变前继
            bt->lchild = pre;
            bt->ltag = 1;
        }
        //此时节点变成前继的后继 继续处理
        if (pre && pre->rchild == NULL)
        {
            pre->rchild = bt;
            pre->rtag = 1;
        }
        pre = bt;
        InThread(bt->rchild, pre);
    }
}

void CreateInThread(ThreadTree t)
{
    ThreadTree pre = NULL;
    if (t)
    {
        InThread(t, pre);
        //后继为空
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

//前序序线索二叉树 正常遍历即可 做一些细节处理
void PreThread(ThreadTree bt, ThreadTree &pre)
{
    if (bt)
    {
        if (!bt->lchild)
        {
            //为空 变前继
            bt->lchild = pre;
            bt->ltag = 1;
        }
        //此时节点变成前继的后继 继续处理
        if (pre && pre->rchild == NULL)
        {
            pre->rchild = bt;
            pre->rtag = 1;
        }
        pre = bt;
        PreThread(bt->lchild, pre);
        PreThread(bt->rchild, pre);
    }
}

void CreatePreThread(ThreadTree t)
{
    ThreadTree pre = NULL;
    if (t)
    {
        PreThread(t, pre);
        //后继为空
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

//后序线索二叉树 正常遍历即可 做一些细节处理
void PostThread(ThreadTree bt, ThreadTree &pre)
{
    if (bt)
    {
        PostThread(bt->lchild, pre);
        PostThread(bt->rchild, pre);
        if (!bt->lchild)
        {
            //为空 变前继
            bt->lchild = pre;
            bt->ltag = 1;
        }
        //此时节点变成前继的后继 继续处理
        if (pre && pre->rchild == NULL)
        {
            pre->rchild = bt;
            pre->rtag = 1;
        }
        pre = bt;
    }
}

void CreatePostThread(ThreadTree t)
{
    ThreadTree pre = NULL;
    if (t)
    {
        PostThread(t, pre);
        //后继为空
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

#pragma endregion