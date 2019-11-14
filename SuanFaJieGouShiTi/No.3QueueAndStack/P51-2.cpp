#include<iostream>
using namespace std;

//长度为Maxsize=M 初始化栈顶指针top1 =-1 top=M+1
typedef struct Stack{
    int top1;
    int Maxsize;
    int *data;
};

void F(){
    Stack s;
    int a,n;
    while (n--)
    {
        cin>>a;
        if(a==-1){
            //说明栈不为空
            if(s.top1!=-1){
                s.top1--;
            }
            else{
                cout<<"栈已经为空无法出栈";
            }
        }
        else{
            if(s.top1!=s.Maxsize){
                s.data[++s.top1]=a;
            }
            else{
                cout<<"栈满出现异常";
            }
        }
    }
}