#include<iostream>
using namespace std;

//长度为Maxsize=M 初始化栈顶指针top1 =-1 top=M+1
typedef struct Stack{
    int top;
    int Maxsize;
    char *data;
};

bool F(char a[],int n){
    //假设栈足够大
    Stack s;
    //只有左括号放进去 若是碰见右括号为空的情况下说明有不匹配
    for(int i=1;i<=n;i++){
        if(a[i]=='('){
            s.data[++s.top]=a[i];
        }
        else if(a[i]==')'){
            if(s.top==-1){
                return false;
            s.top--;
            }
        }
    }
    //此时匹配完成若栈不为空说明有剩余的有问题
    return s.top==-1?true:false;
}