#include <iostream>
using namespace std;

//每次选取最短的俩个元素进行合并
//设Pj为带有头节点的链表,且头节点下的data表示链表长度
typedef struct node
{
    node *next;
    int data;
} * LinkList;

LinkList Merge(LinkList list[], int k)
{
    //k个需要合并k-1次
    for (int i = 1; i < k; i++)
    {
        int min1 = 1, min2 = 1;              //选择长度最短的俩个节点有
        for (int i = 2; i <= k - i + 1; i++) //每次合并一次就把最末尾的节点交换下 使总序列长度变短 方便计算
        {
            if (min2 > list[i]->data)
            {
                if (min1 > list[i]->data)
                {
                    min2 = min1;
                    min1 = i;
                }
                else
                    min2 = i;
            }
        }
        //挑选完之后开始合并存储在min1中之后min2与最末尾交换位置 rear尾巴用于插入
        LinkList min1List = list[min1]->next, min2List = list[min2]->next, rear = list[min1];
        list[min1]->next = NULL;
        while (min1List && min2List)
        {
            if (min1List->data > min2List->data)
            {
                rear->next = min2List;
                min2List = min2List->next;
            }
            else
            {
                rear->next = min1List;
                min1List = min1List->next;
            }
            rear->next = NULL;
        }
        rear->next=min1List?min1List:min2List;
        swap(list[min2],list[k-i+1]);
    }
    //List[1]存放合并好的
    return list[1];
}
