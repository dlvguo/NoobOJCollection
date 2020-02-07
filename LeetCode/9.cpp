#include <iostream>
#include<vector>
using namespace std;

//内存法
bool isPalindrome(int x)
{
    if(x<0)
        return false;
    int count=0,num=x;
    vector<int> nums;
    while (num)
    {
        count++;
        nums.push_back(num%10);
        num/=10;
    }
    for (int l = 0,high=count-1; l<high; l++,high--)
    {
        if(nums[l]!=nums[high])
            return false;
    }
    return true;

}

//还有一个从尾巴*=10 若跟原来一样则为回文  同时去掉-1的情况
bool Judge(int x){
    if(x<0)
        return false;
    long long num=0,temp=x;
    while (x)
    {
        num=num*10+x%10;
        x/=10;
    }
    return num==temp;
}