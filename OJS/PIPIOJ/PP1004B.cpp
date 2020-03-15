#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

struct node
{
    int a;
    int b;
    int value;
} nodes[1000];
int m, n;
int id[111];

//按距离排列Node
void Sort(int n)
{
    for (int i = 1; i <= n; i++)
    {
        node temp = nodes[i];
        int index = i;
        for (int j = i + 1; j <= n; j++)
        {
            index = temp.value > nodes[j].value ? j : index;
        }
        if (index != i)
        {
            temp = nodes[index];
            nodes[index] = nodes[i];
            nodes[i] = temp;
        }
    }
}

void Union(int num, int index)
{
    int a = nodes[num].a;
    int b = nodes[num].b;
    if (!id[a] && !id[b])
        id[a] = id[b] = index;
    else if (!id[a])
    {
        id[a]=id[b];
    }
    else if(!id[b])
        id[b]=id[a];
    else
    {
        int id1 = id[a];
        int id2 = id[b];
        for (int i = 1; i <= m; i++)
            if (id[i] == id2)
                id[i] = id1;
    }
}

void Find()
{
    int value = nodes[1].value;
    int index = 2;
    id[nodes[1].a] = 1;
    id[nodes[1].b] = 1;
    for (int i = 2; i <= n; i++)
    {
        int a = nodes[i].a;
        int b = nodes[i].b;
        if (id[a] == id[b] && id[a])
            continue;
        Union(i, index++);
        value += nodes[i].value;
    }
    int idindex = id[1];
    for (int i = 2; i <= m; i++)
    {
        if (id[i] != idindex)
        {
            idindex = id[i];
            break;
        }
    }
    if (idindex != id[1])
        cout << "?\n";
    else
    {
        cout << value << endl;
    }
}

int main()
{
    while (cin >> m >> n)
    {
        memset(id, 0, sizeof(id));
        for (int i = 1; i <= n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            nodes[i].a = a;
            nodes[i].b = b;
            nodes[i].value = c;
        }
        Sort(n);
        Find();
    }

    return 0;
}