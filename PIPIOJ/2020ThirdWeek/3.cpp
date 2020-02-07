#include <iostream>
#include <hash_set>
#include <queue>
using namespace std;
using namespace __gnu_cxx;

#define POINT 4581298449

struct Button
{
    int status;
    int step = 0;
    int nums[5] = {0};
};

void Set(unsigned long long &num, int n)
{
    num = num | (1 << (n - 1));
}

int main()
{
    hash_set<int> visit;
    queue<vector<Button>> bqueue;
    vector<Button> bts;
    int temp;
    unsigned long long setNum = 0;
    for (int i = 0; i < 9; i++)
    {
        Button b;
        for (int j = 0; j < 5; j++)
        {
            cin >> temp;
            if (!j)
            {
                //设置下位数
                Set(setNum, i * 4 + temp);
                b.status = temp;
            }
            else
            {
                //赋值
                b.nums[j] = temp;
            }
        }
        bts.push_back(b);
    }
    bqueue.push(bts);
    int step = 0;

    while (!bqueue.empty() && step == 0)
    {
        bts = bqueue.front();
        bqueue.pop();
        //9个都可以旋转

        for (int i = 0; i < 9; i++)
        {
            vector<Button> tempbts;
            for (int j = 0; j < 9; j++)
            {
                tempbts.push_back(bts[i]);
            }
            
            setNum = 0;
            tempbts[i].status++;
            if (tempbts[i].status == 5)
                tempbts[i].status = 1;
            int num = tempbts[i].nums[tempbts[i].status];
            tempbts[num].status++;
            if (tempbts[num].status == 5)
                tempbts[num].status = 1;

            for (int j = 0; j < 9; j++)
            {
                Set(setNum, j * 4 + tempbts[j].status);
                tempbts[j].step++;
            }
            if (setNum == POINT)
            {
                step = tempbts[0].step;
                break;
            }
            //插入成功
            if (visit.insert(setNum).second)
            {

                bqueue.push(tempbts);
            }
        }
    }
    if (step)
    {
        cout << step << endl;
    }
    else
    {
        cout << -1;
    }
    system("pause");
}