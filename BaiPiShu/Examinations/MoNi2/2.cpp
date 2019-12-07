#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;

//思路:设数组a[N]当喊过的置为1 未喊过的为0 设置一个数量统计还剩下多少人需要喊 
//同时考虑m=0 说明依次喊出即可其次 当m>n的时候 避免多余循环只需要喊m%(剩余人数)即可

void Josephus(int n,int s,int m){//表示n个人 从第s个人开始报数 每报到m即推出
    if(m==0){
       return;
    }
    int *a=new int[n+1],remainPeople=n,nowNumber=0,nowIndex=s,number;
    number=m>remainPeople?m%remainPeople:m;//表示要喊的数 每次都更新一次
    while (remainPeople)
    {
        if(a[nowIndex]==0){//未喊过
            nowNumber++;
        }
        if(nowNumber==number){//说明此人退出
            cout<<nowIndex;
            remainPeople--;
            number=m>remainPeople?m%remainPeople:m;
            a[nowIndex]=1;
        }
        //更新数组下标 为1-n
        nowIndex=nowIndex>n?1:nowIndex+1;
    }
}

//书中原地置换找到的放在最后 注意下标