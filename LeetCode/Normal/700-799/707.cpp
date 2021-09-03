#include <bits/stdc++.h>
using namespace std;
class MyLinkedList
{
public:
    /** Initialize your data structure here. */

    typedef struct node
    {
        node *next = NULL;
        int val;
    } * LinkedList;
    LinkedList list;
    MyLinkedList()
    {
        list = new node;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        //设计头节点不带返回值
        LinkedList head = list->next;
        while (index && head->next)
        {
            head = head->next;
            index--;
        }
        return head && index == 0 ? head->val : -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        LinkedList p = new node;
        p->val = val;
        p->next = list->next;
        list->next = p;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        LinkedList p = new node;
        p->val = val;
        LinkedList h = list;
        while (h->next)
        {
            h = h->next;
        }
        h->next = p;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        int num = 0;
        LinkedList pre = list, head = list->next;
        while (num < index && head)
        {
            pre = head;
            head = head->next;
            num++;
        }
        if (head)
        {
            LinkedList p = new node;
            p->val = val;
            p->next = head;
            pre->next = p;
        }
        else if (num == index)
        {
            LinkedList p = new node;
            p->val = val;
            pre->next = p;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        int num = 0;
        LinkedList pre = list, head = list->next;
        while (num < index && head->next)
        {
            pre = head;
            head = head->next;
            num++;
        }
        if (num == index)
        {
            pre->next = head->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */