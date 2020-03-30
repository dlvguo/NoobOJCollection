#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f;
//Flyod算法即可
int Mini(int **map,int n,int i,int j){
    //设数组下标0开始
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            for (int k = 0; k <n; k++)
            {
                if(map[j][i]==INF||map[i][k]==INF)
                    continue；
            }
            int temp=map[j][i]+map[i][k];
            if(temp<map[j][k])
                map[j][k]=temp;
        }
    }
    return map[i][j];
}