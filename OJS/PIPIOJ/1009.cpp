#include <iostream>
#include <cstring>
#include<cstdio>
using namespace std;

double map[1001][1001];
int cover[1001];
int n, from, to;
double maxSafe;

void dfs(int nowPoint,double ans){
    if(map[nowPoint][to]){
        ans*=map[nowPoint][to];
        maxSafe=maxSafe<ans?ans:maxSafe;
        return;
    }
    for(int i=1;i<=n;i++){
        if(cover[i])
            continue;
        if(map[nowPoint][i]){
            cover[i]=1;
            dfs(i,ans*map[nowPoint][i]);
            cover[i]=0;
        }
    }
}

int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                double k;
                cin >> k;
                map[i][j] = k;
                cover[i] = 0;
            }
        }
        int m;
        cin >> m;
        while (m--)
        {
            cin >> from >> to;
            cover[from]=1;
            maxSafe=-1;
            dfs(from,1);
            if(maxSafe!=-1)
                printf("%.3f\n",maxSafe);
            else
                cout<<"What a pity!\n";
            cover[from]=0;
        }
    }
    return 0;
}