#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
  deque<char> myque;
    stack<char> helper;
    for(int i=0;i<s.size();++i)
    {
        while(i<s.size()&&s[i]!=']')
        {
            myque.push_back(s[i]);
            ++i;
        }
        if(i==s.size())
            break;
        while(!myque.empty()&&myque.back()!='[')
        {
            helper.push(myque.back());
            myque.pop_back();
        }
        if(myque.back()=='[')
            //cout<<"success"<<endl;
        myque.pop_back();  //删除 '['
        while(!myque.empty()&&isdigit(myque.back()))
        {
            helper.push(myque.back());
            //cout<<myque.back()<<endl;
            myque.pop_back();
        }
        int ret=0;
        string str;
        while(!helper.empty())
        {
            //cout<<helper.top()<<endl;
            if(isdigit(helper.top()))
                ret=ret*10+helper.top()-'0';
            else
                str+=helper.top();
            helper.pop();
        }
        string a;
        for(int j=0;j<ret;++j)
            a+=str;
        //cout<<a<<endl;
        for(int j=0;j<a.size();j++)
            myque.push_back(a[j]);
        for(int j=0;j<myque.size();++j)
        {
            cout<<myque[j]<<endl;
        }
        cout<<"!!!!!!!!!!!!!!!!!!"<<endl;
    }
    string ans;
    while(!myque.empty())
    {
        ans+=myque.front();
        myque.pop_front();
    }
    return ans; }
};