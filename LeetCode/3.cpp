#include <bits/stdc++.h>
#include <iostream>
#include<cstring>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int len=s.length();
    int a[128]={0};
    int left=0,right=0,max=0,temp=0;
    while (left<len)
    {
        while (right<len)
        {
            int index=s[right]-'\0';
            if(a[index]){//说明重复了
                if(temp>max){
                    max=temp;
                }
                //尺取下去
                index=s[left]-'\0';
                a[index]=a[index]==0?0:a[index]-1;
                left++;
                temp--;
                break;
            }
            temp++;
            a[index]=1;
            right++;
        }      
        if(right==len|| (len-right)+temp<=max)
            break;
    }
    if(temp>max)
        return temp;
    return max;
}

int main()
{
    string str="a";
    cout<<lengthOfLongestSubstring(str);
}