#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*  
    一开始采用简单映射发现事情没那么简单，因为这个对应的user和item不是一对一映射而是多对多

    思路：种类并查集，将具有关联user和item映射在一个集合中   
*/


const int LIMIT = 2e5 + 10;
int set[LIMIT];  //表示user和item的并查集 因为有俩种类别不能重复于是用n+i映射表示user i表示item
int city[LIMIT]; //city[i]表示祖先节点为i对应的城市id

//寻找祖先 并路径压缩
int find(int a)
{

    if (set[a] == a)
        return a;
    return set[a] = find(set[a]);
}

//联合
void united(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    //不在一个集合
    if (fa != fb)
        //优先联合city存在的
        if (city[fa])
        {
            set[fb] = fa;
        }
        else
        {
            set[fa] = fb;
        }
}

int main()
{
    //种类并查集的联合
    int n, m, q, userId, cityId, itemId;
    while (~scanf("%d%d%d", &n, &m, &q))
    {
        for (int i = 1; i <= n + m; i++)
        {
            set[i] = i; //初始化每个都是头节点 n+i表示user
            city[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &itemId, &cityId);
            if (cityId)
            {
                int itemfa = find(itemId);
                city[itemfa] = cityId;
            }
        }

        while (m--)
        {
            scanf("%d%d%d", &userId, &itemId, &cityId);
            //俩个先联合下 usetId+n进行映射在一个集合中
            united(userId + n, itemId);
            if (cityId)
            {
                int itemfa = find(itemId);
                city[itemfa] = cityId;
            }
        }
        while (q--)
        {
            int a, id;
            scanf("%d%d", &a, &id);
            if (a)
            {            //说明是user
                id += n; //+n映射
            }
            cityId = city[find(id)];
            printf("%d\n", cityId);
        }
    }
}
