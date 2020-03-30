#include<iostream>
#include<cstring>
using namespace std;

//使用尺取法暴力 首先从str1下标0开始跟str2逐一对比 若str[0]在str1[1]中找到了 则从str[1]继续下标找若没有 str[2]跳下一个 
//类推从1-n遍历 使用个数组存放 当有最新的时候 对比长度更新
void MaxPublicConsequence(char *str1,char *str2,int n){
    char *maxStr=new char[n],*temp=new char[n],maxLen=0,tempLen=0;
    for (int i = 1; i <=n; i++)//1开始往后面叠代
    {
        int str1index=i,str2Index=1;
        tempLen=0;
        while (str1index<=i)//从i开始叠带直至上边遍历到底了 则从新开始
        {
            bool isFind=false;
            for (int k = str2Index; k <=n; k++)
            {
                if(str1[str1index]==str2[k]){
                    temp[tempLen++]=str1[k];
                    str2Index=k+1;
                    str1index++;
                    isFind=true;
                }
            }
            if(!isFind)//此次没找到str1Index++
            str1index++;
        }
        if(tempLen>maxLen){
            maxLen=tempLen;
            maxStr=temp;
        }
    }
    cout<<maxStr;
}


//还有一个dp重叠子问题法 分成最优子结构 从后看 若Xn==ym 说明其余子序列在前方 要么在1-Xn 1-Ym-1 要么在1-Xn-到1-Ym
//dp[n][m]表示n和m最大子结构 于是dp[1-n][0]=0; dp[0][1-m]=0

int FigureMin(char str1[],char str2[]){
    int n=strlen(str1),m=strlen(str2);
    int dp[50][50];
    
    for (int i = 0; i <n; i++)//因为数组下标0——n-1 于是为了方便计算dp[n][m]表示到的 每次计算i+1 j+1
    {
        for (int  j = 0; j <m; j++)
        {
            if(str1[i]==str2[j]){
                dp[i+1][j+1]=1+dp[i][j];
            }
            else if(dp[i][j+1]>dp[i+1][j]){
                dp[i+1][j+1]=dp[i][j+1];
            }
            else 
                dp[i+1][j+1]=dp[i+1][j];
        }
    }
    return dp[n-1][m-1];
}

int main(){
    char *a="bcdf",*b="bcde";
   cout<< FigureMin(a,b);
}


