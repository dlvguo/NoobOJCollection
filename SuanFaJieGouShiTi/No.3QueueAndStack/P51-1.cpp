#include<iostream>
using namespace std;

//长度为Maxsize=M 初始化栈顶指针top1 =-1 top=M+1
typedef struct Stack{
    int top1,top2;
    int Maxsize;
    int *data;
};

//num1 表示1号栈 2表示2号栈 
bool Empty(int num,Stack s){
    if(num==1)
        return s.top1==-1;
    return s.top2==s.Maxsize+1;
}

//判断栈满
bool Full(Stack s){
    return s.top1+1==s.top2;
}

//入栈
bool Push(int num,int key,Stack s){
    if(Full(Stack))
        return false;
    if(num==1)
        s.data[++s.top1]=key;
    else
    {
         s.data[--s.top2]=key;
    }
    return true;
}

//出栈 
bool Pop(int num,int &key,Stack s){
    if(Empty(num,s))
        return false;
    key=num==1?s.data[s.top1--]:s.data[s.top2++];
    return true;
}