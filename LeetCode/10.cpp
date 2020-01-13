#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool FirstMatch(char a,char b){
    return a==b||b=='.';
}

bool isMatch(char *s, char *p)
{
    //匹配式为0的话
    if(*p==0)
        return *s==0;
    if(*(p+1)=='*'){
        return isMatch(s,p+2)||(*s&&FirstMatch(*s,*p)&&isMatch(s+1,p));
    }
    return *s&&FirstMatch(*s,*p)&&isMatch(s+1,p+1);
}

int main()
{
    char *s ="mississippi", *p ="mis*is*p*.";//空就为0
    cout<<isMatch(s,p);
}