#include<iostream>
#include"../../Headers/BinaryTree.h"
using namespace std;

//假设p在q的左边
BiTree FindAncestor(BiTree p,BiTree q,BiTree bt){
    //用俩个辅助栈 stack表示后序中路径长的那个元素 stack1表示短的那个序列
    //假设栈足够大
    BiTree stack[],stack1[];
    int top=-1,top1=-1;
    //point表示目标节点 pre表示访问的上一个节点 用于后序判断中右子树是否访问
    BiTree point=bt,pre=NULL;
    while (top!=-1||point)
    {
        while (point&&point!=p&&point!=q)
        {
            stack[++top]=point;
            point=point->lchild;
        }
        //说明到最左节点
        if(point=NULL&&top!=-1){
            point=stack[top];
            //说明右节点未访问
            if(point->rchild!=pre){
                point=point->rchild;
            }
            //出栈
            else{
                top--;
                pre=point;
                point=NULL;
            }
        }
        //说明p已经进栈 往前找！
        else if(top1!=-1){
            for(int i=top1;i>=1;i--)
                for(int j=top;j>=1;j--)
                    if(stack[j]==stack1[i])
                        return stack[j];
            return NULL;
        }
        
    }
    
    return NULL;
}
