#include <iostream>
#include <cstring>
using namespace std;

//根据长度创建len
int* CreatyIntArr(int len){
    int *p=(int *)malloc(sizeof(int)*len);
    for(int i=0;i<len;i++){
        int a;
        cin>>a;
        p[i]=a;
    }
    return p;
}

//输出数组
void PrintArr(int a[],int len){
    for (int i = 0; i < len; i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
