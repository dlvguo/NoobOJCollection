#include <iostream>
#include "../../Headers/array.h"
using namespace std;
//重载因子 0.8 100个元素 故表长125 p取127 H(3*i+2*j)%p
#define m 127

typedef struct node
{
    int row, volum, value;
} Node, HT;

void Insert(HT ht[])
{
    //初始化赋值 0代表无内容
    for (int i = 0; i < m; i++)
        ht[i].value = 0;
    for (int i = 0; i < 100; i++)
    {
        int row, volum, value;
        cin >> row >> volum >> value;
        int index = (row * 3 + volum * 2) % m;
        //如果有东西继续探测
        while (ht[index])
        {
            index = (index + 1) % m;
        }
        ht[index].row = row;
        ht[index].volum = volum;
        ht[index].value = value;
    }
}

int main()
{

    return 0;
}