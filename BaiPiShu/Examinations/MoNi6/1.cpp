#include<iostream>
#include<math.h>
using namespace std;
//如果输出全排列的话 可用2进制表示状态位 则需要n个二进制表表示这n个状态位 遍历即可
void PrintAll(int n){
    long long b=pow(2,n);
    for (int i = 1; i <b; i++)
    {
        //第i个位置为1 表示i属于这个集合
        int temp=i,index=1;
        while (temp)
        {
            if(temp%2)
                cout<<index;
            index++;
            temp=temp>>1;
        }
        cout<<endl;
    }
}

int main(){
    PrintAll(3);
}