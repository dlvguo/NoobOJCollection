#include <iostream>
#include "../../Headers/array.h"
using namespace std;
bool judge(int a[], int n)
{
    //用数组模拟栈的操作 从1-n开始进栈 碰见和数列中一样的出栈 直到完全进栈 若指针为为-1 则代表序列符合
    int *b = new int[n];
    int i = 0, point = -1, aindex = 0;
    while (i < n)
    {
        //为空或者不同
        if (point == -1 || b[point] != a[aindex])
        {
            b[++point] = a[i++];
        }
        //放入新的进行后进行判断
        if (b[point] == a[aindex])
        {
            point--;
            aindex++;
        }
    }
    return point == -1 ? true : false;
}

int main()
{
    freopen("C:/NoobOJCollection/BaiPiShu/No.3Stack/P98-6.txt", "r", stdin);
    int *a = CreatyIntArr(3);
    PrintArr(a, 3);
    cout << judge(a, 3);
}