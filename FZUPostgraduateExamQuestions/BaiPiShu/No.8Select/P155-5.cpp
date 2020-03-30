#include <iostream>
#include <cstring>
using namespace std;

//2-d树
typedef struct node2d
{
    char *key1, *key2;
    node2d *lchild, *rchild;
} * Tree2d;

//初始化为1
void Insert(Tree2d &t, char *key1, char *key2, int height = 1)
{
    if (t == NULL)
    {
        t = new node2d;
        t->key1 = key1;
        t->key2 = key2;
        t->lchild = t->rchild = NULL;
        return;
    }
    //奇数层用key1
    int compare = height % 2 ? strcmp(key1, t->key1) : strcmp(key2, t->key2);
    if (compare == 0)
        return;
    else if (compare > 0)
    {
        Insert(t->rchild, key1, key2, height + 1);
    }
    else
    {
        Insert(t->lchild, key1, key2, height + 1);
    }
}
