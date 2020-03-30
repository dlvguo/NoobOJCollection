#include <iostream>
#include "../../Headers/linkList.h"
#include "../../Headers/array.h"
using namespace std;

//考虑俩种情况 1、2
void Union(LinkList &A, LinkList B)
{
    //A和B同时开始扫描 若当前A<B 删A A=B下一个 A<B B下一个 避免重复元素
    Node *ap = A, *aprear = NULL;
    int temp;
    while (ap&&B)
    {
        if(ap->data<B->data){
            ap=ap->next;
        }
        else if(ap->data>B->data){
            B=B->next;
        }
        else{
            //代表第一个这时候头节点为当前指针
            if(aprear==NULL){
                A=ap;
                aprear=A;
                temp=aprear->data;
            }
            else if(temp!=ap->data){
                aprear->next=ap;
                aprear=aprear->next;
                temp=aprear->data;
            }
            ap=ap->next;
            B=B->next;
            aprear->next=NULL;
        }
    }    
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/XianXingBiao/P91-15.txt", "r", stdin);

    LinkList A, B;
    int *a = CreatyIntArr(6), *b = CreatyIntArr(5);
    InitList(A,a,6,false);
    InitList(B,b,5,false);
    Union(A, B);
    PrintList(A,false);
    return 0;
}