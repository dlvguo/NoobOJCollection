#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int len=nums.size();
    if(len==0)
        return len;
    int pre=nums[0],moveCount=0;
    for (int i = 1;i<len; i++)
    {
        if(nums[i]==pre){
            moveCount++;
        }
        else{
            nums[i-moveCount]=nums[i];
            pre=nums[i];
        }
    }
    len-=moveCount;
    return len;
}

int main()
{

}
