#include <iostream>
#include "../../Headers/array.h"
using namespace std;

void FindMin(int a[], int len)
{
    //使得数组下标1 表示是否有1的 依次类推
    int *b=new int[len+1];
    for(int i=1;i<=len;i++)
        b[i]=0;
    for (int i = 0; i < len; i++)
    {
        if(a[i]>0&&a[i]<=len){
            b[a[i]]=1;
        }
    }
     for(int i=1;i<=len;i++)
        if(b[i]==0){
            cout<<i<<endl;
            return;
        }    
    cout<<len+1<<endl;
}

int main()
{
    freopen("C:/NoobOJCollection/WandDao/No2.XianXingBiao/P19-13.txt", "r", stdin);
    int *a = CreatyIntArr(5);
    FindMin(a, 5);
}
