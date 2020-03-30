#include<iostream>
#include"../../Headers/linkList.h"
using namespace std;

//链表形式
int SearchList(LinkList &list,int key){
    Node *pre=NULL,*p=list;
    int index=1;
    while (p)
    {
        if(p->data==key){
            //表示已经是头节点
            if(!pre)
                return index;
            else{
                //交换节点数据即可
                int temp=pre->data;
                pre->data=p->data;
                p->data=temp;
                return --index;
            }
        }
        pre=p;
        p=p->next;
    }
    //未找到
    return -1;
}

struct  SqlList{
    int len;
    int *data;
}

int SearchSql(SqlList sql,int key){
    
    for (int i = 0; i < sql.len; i++)
    {
        if(sql.data[i]==key){
            if(i==0)
                return 0;
            int temp=sql.data[i-1];
            sql.data[i-1]=sql[i];
            sql.data[i]=temp;
            return i-1;
        }
    }
    return -1;
}
