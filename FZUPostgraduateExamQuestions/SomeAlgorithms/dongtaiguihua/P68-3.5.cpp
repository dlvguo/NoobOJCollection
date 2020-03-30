#include<iostream>
using namespace std;
//数字三角问题 自底向上

//设数组下标为1-n
void CountMax(int a[][]){
    for(int row=n-1;row>=1;row--)
        for(int col=1;col<=row;col++){
            if(a[row+1][col]>a[row][col+1])
                a[row][col]=a[row+1][col];
            else
            {
                a[row][col]=a[row+1][col+1];
            }
            
        }
    //MAX
    cout<<a[1][1];
}