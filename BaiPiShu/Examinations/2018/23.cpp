#include <iostream>
using namespace std;
//先用一个数组C[n]表示这些数的存在 如A中存在2 c[2]表示1 后面依次遍历看下就好
//上述方法思想符合 但是有多种方法可以解决问题 上述方法用的数组可以选a和b中最大的值建立 数组 然后选中小的逐一比较
//可以用hash 来解决集合冲突
int FindHeroNumber(int a[], int b[], int na, int nb)
{
    int c[]; //假设c足够大
    for (int i = 0; i < na; i++)
    {
        c[a[i]] = 1;
    }
    int count = 0;
    for (int i = 0; i < nb; i++)
    {
        if (c[b[i]])
            count++;
    }
    return count;
}

//方案2 a和b数组中都有最大值和最小值 然后不断向中间缩小 直到一方结束 可以使用分冶法 并且每次找到的最小和最大放到边界
//这样向中间缩小 当左边界高于右边界的时候 说明查找完成 时间主要是花在找最大值和最小值上面
//找到最大值后并在最大值放在high的位置 最小值放在low位置
void FindValue(int a[], int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        if (a[i] > a[high])
            swap(a[i], a[high]);
        if (a[i] < a[low])
            swap(a[i], a[low]);
    }
}

int Search(int a[], int b[], int alow, int ahigh, int blow, int bhigh)
{
    if (alow > ahigh || blow > bhigh)
        return 0;
    //找a和b最大值
    FindValue(a, alow, ahigh);
    FindValue(b, blow, bhigh);
    int sum = 0;
    if (a[alow] == b[blow])
    {
        sum++;
        alow++;
        blow++;
    }
    else if (a[alow] > b[blow])
        blow++;
    else
        alow++;
    if (a[ahigh] == b[bhigh])
    {
        ahigh--;
        bhigh--;
        sum++;
    }
    else if (a[ahigh] > b[bhigh])
        ahigh--;
    else
        bhigh--;
    return sum+Search(a,b,alow,ahigh,blow,bhigh);
}

//方案3 使用快排后依次比较 O(NLogN)
