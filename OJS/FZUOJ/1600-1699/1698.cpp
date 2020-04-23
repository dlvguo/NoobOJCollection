#include <iostream>
#include <math.h>
#include <vector>
#include <deque>
#include <stdio.h>
using namespace std;

/*
    思路：要使数尽可能多且每个数不能一样，用贪心思想从2-3-4-5开始分，直到不可分割之后，从最大的数往前累加到1,因为数字较大使用大数计算
    比如：24 一开始为 2 3 4 5 6 余4 累加一轮为 2 4 5 6 7

*/

//大数相乘 注意位置对齐即可
vector<int> BigDateMul(vector<int> nums, int n)
{
    int index = 0;
    vector<int> temp;
    while (n)
    {
        //进位 
        int dig = 0, num = n % 10;
        for (int i = 0; i < nums.size(); i++)
        {
            //上一步的进位
            dig += num * nums[i];
            if (index + i >= temp.size())
            { //说明超了
                temp.push_back(dig % 10);
            }
            else
            {
                dig += temp[i + index];
                temp[i + index] = dig % 10;
            }
            dig /= 10;
        }
        if (dig)
        {
            temp.push_back(dig);
        }
        n /= 10;
        index++;
    }
    return temp;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 3)
        {
            cout << "1 2\n2\n";
        }
        else if (n == 4)
        {
            cout << "1 3\n3\n";
        }
        else
        {
            //存放所有的数字
            vector<int> allNum;
            int k = 2;
            while (k <= n)
            {
                allNum.push_back(k);
                n -= k;
                k++;
            }
            //从后向前累加 可能有几轮
            while (n)
            {
                for (int i = allNum.size() - 1; i >= 0 && n; i--, n--)
                {
                    allNum[i]++;
                }
            }

            //存放最后的大数
            vector<int> nums;
            int num = allNum.back();
            //转换成数组
            while (num)
            {
                nums.push_back(num % 10);
                num /= 10;
            }
            //相乘
            for (int i = allNum.size() - 2; i >= 0; i--)
            {
                nums = BigDateMul(nums, allNum[i]);
            }
            printf("%d", allNum.front());

            for (int i = 1; i < allNum.size(); i++)
            {
                printf(" %d", allNum[i]);
            }
            printf("\n");
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                printf("%d", nums[i]);
            }
            printf("\n");
        }
    }
}