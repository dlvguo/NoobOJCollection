#include <iostream>
using namespace std;

typedef struct node
{
     node *lchild,*rchild;
     int key;
     int count;
}*Bitree;

//寻找第k个
int SearchKey(Bitree bt,int k){
    int count=bt->count+1;//代表包含此节点的count数量
    if(count==k) 
        return bt->key;
    //数量不足找不到
    else if(count<k)
    {
         return 0;
    }
    else {
        int key=SearchKey(bt->lchild,k);
        //如果在左子树中 搜索到
        if(key)
            return key;        
        //根据二叉排序树左节点和根节点均小于右子树的节点，故传入右子树的k值可以减去左子树的节点+1
        k=bt->rchild?k-bt->lchild->count-2:k-1;
        return (bt->rchild,k);
    }
    
}