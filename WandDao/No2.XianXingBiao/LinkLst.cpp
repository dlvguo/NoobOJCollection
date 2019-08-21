#include<iostream>
using namespace std;

typedef int DataEle;
typedef struct LNode{
    DataEle data;
    LNode * Next;
}LNode,*LinkList;

//P39 12题
void Del_Same(LinkList &L){
    LNode *head=L;
    while (head->Next!=NULL)
    {
        head=head->Next;
        if(head->Next->data==head->data){
            while (head->data==head->Next->data&&head->Next)
            {
                head->Next=head->Next->Next;
            }
        }        
    }
}

//P39 14题
void MergeLink(LinkList &A,LinkList &B){
    LinkList C=new LNode;
    C->Next=NULL;
    LNode *aHead=A,*bHead=B;
    while (aHead->Next&&bHead->Next)
    {
        aHead=aHead->Next;
        bHead=bHead->Next;
        if(aHead->data==bHead->data){
            LNode *node=new LNode;
            node=aHead;
            C->Next=node;
            C=C->Next;
            continue;
        }
        else if(aHead->data>bHead->data){
            bHead=bHead->Next;
            continue;
        }
        else
        {
            
            aHead=aHead->Next;
        }
        
        /* code */
    }
}

//P39 17
//从头

int main(){}
