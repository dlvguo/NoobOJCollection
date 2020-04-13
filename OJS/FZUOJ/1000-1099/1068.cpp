#include <iostream>
#include <set>
using namespace std;

set<int> _set;
int nums[505] = {0};
set<int>::iterator it;

/*一个集合S的数包括：
    1.一个整数m每个位数之和等于每个位数之积
    2.m*2,也属于这个集合
*/
//打表法即可

bool Judge(int x)
{
    //除2看看是否已经在集合中
    if (x % 2 == 0)
    {
        it = _set.find(x / 2);
        if (it != _set.end())
            return true;
    }
    int j = 1, sum = 0;
    while (x)
    {
        j *= (x % 10);
        sum += (x % 10);
        x /= 10;
    }
    return sum == j;
}

int main()
{
    int count = 1;
    for (int i = 1; count <= 500; i++)
    {
        if (Judge(i))
        {
            nums[count++] = i;
            _set.insert(i);
        }
    }
    int n, k;
    cin >> n;
    while (n--)
    {
        cin >> k;
        cout << nums[k] << endl;
    }
}
