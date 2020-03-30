#include <iostream>
using namespace std;

typedef struct node
{
    node * next,*particular;
    int data;
}*LinkList;


//三种思路
//思路一找到复制一波 然后每次找去找一波 需要O(n2)
//思路二用hashmap映射如A->A ,在hash map中a当key a'当value
//思路三 a->b 复制一波 a->a'->b->b' 这样好连 之后删除a即可
