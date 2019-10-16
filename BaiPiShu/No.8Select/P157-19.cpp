#include <iostream>
#include"../../Headers/BinaryTree.h"
#include<math.h>
using namespace std;

//判断
int JudgeBalance(BiTree bt){
    if(bt==NULL)
        return 0;
    //平衡因子等于左子树-右子树高度
    int hl=JudgeBalance(bt->lchild),hr=JudgeBalance(bt->rchild);
    //返回-1表示错误不平衡
    if(hl==-1||hr==-1||abs(hr-hl)>1)
        return -1;
    //返回本层高度
    return hl>hr?1+hl:1+hr;
}