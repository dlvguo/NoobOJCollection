#include<iostream>
using namespace std;
//租用游艇问题 类似最短路径算法 Floyd 算法

#define N 100
//代表路径
int map[N+1][N+1];
//求1-N的最短 
int FigurShortest(){
    //区间很困扰 就记住2开始 然后i从1到最大-1 然后j是i与l-1 之后k他们直接 遍历即可
    //类似模板 可处理一般动态规划划线问题
    for (int l = 2; l<=N; l++)
    {
        for (int i = 1; i <=N-l+1 ; i++)
        {
            int j=i+l-1;
            for(int k = i+1; k<j; k++)
            {
                int temp=map[i][k]+map[k][j];
                map[i][j]=map[i][j]<temp?map[i][j]:temp;
            }
            
        }
        
    }
    return map[1][N];
}