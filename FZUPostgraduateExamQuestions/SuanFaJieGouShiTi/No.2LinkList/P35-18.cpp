#include<iostream>
#include"../../Headers/linkList.h"
using namespace std;

//删除节点中相同的值
void DelteXt(int pre,LinkList a){
    LinkList p;
    while (a)
    {
        if(pre==a->data){
            p=a;
            a=a->next;
            delete p;
        }
        else{
            pre=a->data;
            a=a->next;
        }
    }
}

//三个链表俩俩循环插入即可
void Merge(LinkList &A,LinkList &B){
    //pa表示A中目标节点 prea表示目标节点的前驱 pb表示遍历B的每一个节点
    LinkList pa=A->next,prea=A,pb=B->next;
    //先确定第一个最先元素放入A中
    if(pa->data>pb->data){
        //将pb第一个节点插入进去
        prea->next=pb;
        prea->next->next=pa;
        prea=prea->next;
        //pb进入下一个
        pb=pb->next;
    }
    //表示上一个插入的元素
    int predata=prea->data;
    while (pa&&pb)
    {
        //如果pa||pb的元素与上一个插入元素相同 删除节点
        if(pa->data==predata){
            prea->next=pa->next;
            delete pa;
            pa=prea->next;
            continue;
        }
        if(pb->data==predata){
            LinkList p=pb;
            pb=pb->next;
            delete p;
            continue;
        }
        if(pa->data<pb->data){
            prea=pa;
            pa=pa->next;
        }
        //将b插入prea之后
        else if(pa->data>pb->data){
            prea->next=pb;
            pb=pb->next;
            prea->next->next=pa;
            prea=prea->next;
        }
        //相等情况删b
        else
        {
            prea=pa;
            pa=pa->next;
            LinkList p=pb;
            pb=pb->next;
            delete p;
        }
    }
    //合并重复节点
    pa=pa?pa:pb;
    DelteXt(predata,pa);
}


void Merge(LinkList &A,LinkList &B,LinkList &C){
    Merge(A,B);
    Merge(A,C);
}