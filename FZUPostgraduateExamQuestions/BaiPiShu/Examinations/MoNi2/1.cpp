#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;

//思路:用一begin[i] end[i]表示 里面有活动开始时间和活动结束时间
//首先先根据活动结束时间递增排序 再根据活动时间递增排序
//这样能保证排在前面的既是最早开始也是最早结束
//然后从前往后选 不冲突就举行活动冲突就换下一个 因为排好序后已经能保证排在前面的在同一时间启动的是持续最短的

int cmp(const int *a, const int *b)
{
    return a < b;
}

int Figure(int begin[], int end[], int n)
{
    qsort(end, n, sizeof(end), cmp);
    qsort(begin, n, sizeof(begin), cmp);
    //拍好序后能保证每次都是前面大的 如有俩个活动是2-3 2-4 则2-3排在2-4前面
    int count = 0, preEnd = -1;
    for (int i = 0; i < n; i++)
    {
        if (preEnd <= begin[i])
        { //
            count++;
            preEnd = end[i];
        }
    }
    return count;
}