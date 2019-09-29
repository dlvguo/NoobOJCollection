#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

BiTree CreateBin(int preorder[], int prestart, int prelen, int inorder[], int instart, int inlen)
{
    if (prestart > prelen)
        return NULL;
    BiTree r = new BiTNode;
    int root = preorder[prestart];
    for (int i = instart; i <= inlen; i++)
    {
        if (root == inorder[i])
        {
            int llen = i - instart;
            int rlen = inlen - i;
            r->data = root;
            //切割左右子树 分别进入
            //Left
            r->lchild = CreateBin(preorder, prestart + 1, prelen+llen, inorder, instart, i - 1);
            //Right
            r->rchild = CreateBin(preorder, prelen-rlen+1; prelen, inorder, i + 1, inlen);
        }
    }
    return r;
}