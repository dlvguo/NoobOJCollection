#include <iostream>
#include <vector>
#include<cstring>
using namespace std;
int findRepeatNumber(vector<int> &nums)
{
    int *n=new int[nums.size()];
    memset(n,0,sizeof(int)*nums.size());
    for (int i = 0; i <nums.size(); i++)
    {
        if(n[nums[i]]==0)
            n[nums[i]]=1;
        else{
            return nums[i];
        }
    }
    return 0;
}

int main()
{
        int *n=new int[5];
            memset(n,0,sizeof(int)*5);
        cout<<n[4];
        system("pause");
}
