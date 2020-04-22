#include <iostream>
#include <math.h>
#include <vector>
#include <deque>
#include <stdio.h>
using namespace std;

//明天做
void BigDateMul(vector<int> &nums, int n)
{
    //大数放在nums中
    int index = 0;
    while (n)
    {
        int dig = 0, num = n % 10;
        for (int i = 0; i < nums.size(); i++)
        {
            //上一步的进位
            dig += num * nums[i];
            if (index + i == nums.size())
            { //说明超了
                nums.push_back(dig % 10);
            }
            else
            {
                dig += nums[i + index];
                nums[i + index] = dig % 10;
            }
            dig %= 10;
        }
        n /= 10;
        index++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 5)
    {
        cout << n - 1 << endl;
    }
    else
    {

        deque<int> dq;

        int numCount = sqrt(n);
        int left = n / numCount - 1, right = n / numCount + 1, sum = 1, remain = n - (n / numCount);
        dq.push_back(n / numCount);
        //分解数 从中间开始计算往左右俩边
        while (sum < numCount)
        {
            //优先添加左边于是有
            if (right <= remain)
            {
                remain -= right;
                dq.push_back(right);
                right++;
                sum++;
            }
            if (left <= remain)
            {
                remain -= left;
                dq.push_front(left);
                left--;
                sum++;
            }
        }
        //有剩下的加在最后面
        if (remain)
        {
            dq.back() += remain;
        }

        vector<int> nums;
        int num = dq.front();
        dq.pop_front();
        while (num)
        {
            nums.push_back(num % 10);
            num /= 10;
        }
        while (dq.size())
        {
            cout << dq.front() << endl;
            dq.pop_front();
        }
    }
    system("pause");
}