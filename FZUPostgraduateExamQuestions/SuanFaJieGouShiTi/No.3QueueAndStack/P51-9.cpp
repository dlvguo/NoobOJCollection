#include <iostream>
using namespace std;

int Ack(int m, int n)
{
    if (m == 0)
        return n + 1;
    if (n == 0)
        return Ack(m - 1, 1);
    return Ack(m - 1, n - 1);
}

//非递归的Ack
int NAck(int m, int n)
{
    while (1)
    {
        if (m == 0)
            break;
        if (n == 0)
        {
            m--;
            continue;
        }
        m--;
        n--;
    }
    return n + 1;
}