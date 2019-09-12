#include<iostream>
using namespace std;

#pragma region //辅助检测部分

void DfsPrint(int n){
    if(n/2)
        DfsPrint(n/2);
    cout<<n%2;
}
//输出二进制
void PrintBin(int n){
    DfsPrint(n);
    cout<<endl;
}
//计算二进制大小
int FigureBinCount(int n){
    int count=1;
    while (n/2)
    {
        count++;
    }
    return count;
}



#pragma endregion