#include <iostream>
#include <stack>
using namespace std;

//用一个辅助栈表示当前最小的值 每次进栈 也进把最小值进辅助栈
typedef struct ParStack
{
    stack<int> minstack,s;
    int min;
};

void Min(ParStack p){
    return p.min;
}

void Push(ParStack p,int key){
    if(p.s.empty()||p.min>key){
        p.min=key;
    }
    p.s.push(key);
    p.minstack.push(p.min);
}

void Pop(ParStack p){
    if(p.s.empty())
        return;
    p.minstack.pop();
    p.s.pop();
    p.min=p.minstack.top();
}