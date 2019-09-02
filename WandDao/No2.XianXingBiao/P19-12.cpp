#include <iostream>
#include "../../Headers/array.h"
using namespace std;

void FindPri(int a[], int len)
{
    //首先将第一个元素作为对比元素 与后面相比，如果相同count+1，不同count-1 若count=0时候说明此元素已经没有 故取新的一个
    //最后count若>0 此数为主元素
    if (len < 1)
        cout << -1;
    int count = 0, mid, i = 0;
    //mid为候选元素 碰见相同的count++ 不同的时候count-- 当count==0的时候 说明前面的候选元素无效 故当前为候选
    while (i < len)
    {
        if (count == 0)
        {
            mid = a[i];
            count = 1;
        }
        else if (mid == a[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        i++;
    }
    if(count<=0){
        cout<<-1<<endl;
    }
    else{
        count=0;
        for(int i=0;i<len;i++){
            if(mid==a[i])
                count++;
        }
        if(count>len/2){
            cout<<len<<':'<<count<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}

int main()
{
    freopen("C:/NoobOJCollection/WandDao/No2.XianXingBiao/P19-12.txt", "r", stdin);
    int *a = CreatyIntArr(5);
    FindPri(a, 5);
}
