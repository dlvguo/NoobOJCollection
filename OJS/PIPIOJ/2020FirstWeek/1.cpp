#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <cstdio>
using namespace std;

void Figure()
{
    int n, q, a, sum = 0;
    char s[55];
    cin >> n >> q;
    set<char *> ss;
    set<char *> add;
    set<char *>::iterator it;
    while (n--)
    {
        scanf("%s", s);
        it = ss.find(s);
        if (it != ss.end())
            sum++;
        else
        {
            ss.insert(s);
        }
    }
    while (q--)
    {
        scanf("%d", &a);

        if (a == 1)
        {
            scanf("%s", s);
            it = add.find(s);
            if (it != add.end())
            {
                sum++;
            }
            else
            {
                it = ss.find(s);
                if (it != ss.end())
                {
                    add.insert(s);
                }
                else
                    ss.insert(s);
            }
        }
        else
        {
            printf("%d", add.size() + sum);
            sum = 0;
            add.clear();
        }
    }
}

int main()
{
    Figure();
}