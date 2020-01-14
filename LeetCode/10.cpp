#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//双指针法
int maxArea(int *height, int heightSize)
{
    int max = 0;
    int low = 0, high = heightSize - 1;
    while (low < high)
    {
        int h = height[low] > height[high] ? height[high] : height[low];
        int temp = (high - low) * h;
        if (temp > max)
            max = temp;
        if (height[low] > height[high])
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    return max;
}

int main()
{
}