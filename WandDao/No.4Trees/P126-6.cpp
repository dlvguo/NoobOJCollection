#include <iostream>
#include "../../Headers/BinaryTree.h"
#include <stack>
using namespace std;

//right to left down to up
//切割数组初试1-N
void CreateBin(int preorder[], int prestart, int prelen, int inorder[], int instart, int inlen, BiTree &bit)
{
    if (prestart > prelen)
        return;
    int root = preorder[prestart];
    for (int i = instart; i <= inlen; i++)
    {
        if (root == inorder[i])
        {
            bit = new BiTNode;
            bit->data = root;
            //切割左右子树 分别进入
            //Left
            CreateBin(preorder, prestart + 1, prestart + i - instart, inorder, instart, i - 1, bit->lchild);
            //Right
            CreateBin(preorder, prestart +i-instart+1; prelen, inorder, i+1, inlen, bit->rchild);
        }
    }
}