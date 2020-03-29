#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int num, count;
        set<int> hashSet;
        while (n--)
        {
            count = 0;
            scanf("%d", &num);
            while (num)
            {
                num = num & (num - 1);
                count++;
            }
            
            hashSet.insert(count);
        }
        printf("%d", hashSet.size());
    }
    return 0;
}