#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    若一个数>=左边且<=右边 放入数组
*/

/*算法思路:
	首先设置一个leftMax代表左边最大值初始为nums[0]，rightMax代表右边最大值，一开始先遍历一次nums求rightMax，
	同时右边使用双端队列维护一个当前最大rightMax队列
	之后开始从nums开始依次遍历，如果当前的nums[i]符合题目要求放入数组
*/
vector<int> search(vector<int> nums)
{
    if (nums.size() == 0)
        return {};
    if (nums.size() == 1) //就一个直接返回即可
        return {nums[0]};
    int leftMax = nums[0];
    deque<int> rightMaxQueue; //当前最大值队列
    rightMaxQueue.push_back(nums[1]);
    //维护一个当前最大队列
    for (int i = 2; i < nums.size(); i++)
    {
        //若值比大于队列末尾 往前放即可，知道不大于的值放入末尾
        while (nums[i] > rightMaxQueue.back())
        {
            rightMaxQueue.pop_back();
        }
        rightMaxQueue.push_back(nums[i]);
    }
    vector<int> pointNums;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= leftMax && nums[i] <= rightMaxQueue.front())
        {
            pointNums.push_back(nums[i]);
        }

        //更新左右俩边最大值
        if (nums[i] > leftMax)
            leftMax = nums[i];
        //右边维护一个当前最大队列 若相等去顶部
        if (nums[i] == rightMaxQueue.front())
        {
            rightMaxQueue.pop_front();
        }
    }
    return pointNums;
}
