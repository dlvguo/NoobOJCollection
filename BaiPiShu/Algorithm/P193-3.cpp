#include <iostream>
using namespace std;

//如果为偶数个的话 就分成俩碟 小的那叠继续迭代
//若有奇数个 分成俩个偶数叠和单个硬币 若前面偶数叠相等则这个单个就为硬币
int FindFalseCoin(int coin[], int low, int high int n)
{
    //分冶法 若只有俩个的时候就比较大小即可
    if (low + 1 == high)
    {
        return coin[low] > coin[high] ? high : low;
    }
    int sum1 = 0, sum2 = 0, sum3 = 0;
    if ((low + high) % 2 == 0)
    { //说明有奇数个
        sum3 = coin[high];
        high--;
    }
    int mid = (low + high) / 2;
    for (int i = 1; i <= high; i++)
    {
        if (i <= mid)
            sum1 += coin[i];
        else
            sum2 += coin[i];
    }
    if(sum1==sum2)
        return high+1;
    else
    {
         if(sum1<sum2)
            return FindFalseCoin(coin,low,mid);
        return FindFalseCoin(coin,mid+1,high);
    }
    
}
