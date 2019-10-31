#include<iostream>
#include"../../Headers/linkList.h"
using namespace std;


//设有俩个链表 Ha 为单链表 Hb为循环单链表 使之链表变成单链表 要求时间复杂度与链表长度无关
//ha为单链表表头 而hb为带尾节点的循环单链表

void Merge(LinkList ha,LinkList hb){
    //hbhead为hb的头节点
    LinkList hbhead=hb->next;
    //hb为尾节点连接ha的next
    hb->next=ha->next;
    //ha连接hb的头节点即完成
    ha->next=hbhead;    
}