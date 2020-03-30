#include <iostream>
using namespace std;


//用并查集 初始化set[i]=i 表示为根节点 之后先把输入数据凑成不同集合  最后合并成一个集合需要几次就为修建的路的次数
int FindRoot(int x, int set[])
{
    if (set[x] == x)
        return x;
    return FindRoot(set[x], set);
}

//联合
void Union(int x,int y,int set[]){
    int yroot=FindRoot(y,set);
    set[yroot]=x;
}

//判断是否为根节点
bool IsRoot(int x,int set[]){
    return set[x]==x;
}

int main(){
    int m,n;
    cin>>m>>n;
    int *set=new int[m+1];
    for (int i = 1; i <=m; i++)
    {
        set[i]=i;
    }
    while (n--)
    {
        int x1,x2;
        cin>>x1>>x2;
        Union(x1,x2,set);
    }
    int sum=0;
    for (int i =1; i <=m; i++)
    {
        if(IsRoot(i,set))
        sum++;
    }
    cout<<sum<<endl;
}
