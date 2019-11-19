#include<iostream>
using namespace std;

bool Judege(){
    char strs[];//假设strs足够大
    int len=0;
    char a;
    while (cin>>a,a!='@')
    {
        strs[len++]=a;
    }
    int low=1,high=len;
    while (low<high)
    {
        if(strs[low]!=strs[high])
            return false;
    }
    return true;
}