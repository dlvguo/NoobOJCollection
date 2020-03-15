#include <iostream>
#include <hash_set>
#include <queue>
using namespace std;
using namespace __gnu_cxx;

struct Button
{
    int status;
    int step = 0;
    int nums[5] = {0};
};
bool visit[10][5] = {0};

//判断是否访问过
bool Judge(vector<Button> bts)
{
    for (int i = 0; i < bts.size(); i++)
    {
        if (!visit[i][bts[i].status])
            return false;
    }
    return true;
}

void SetBtn(vector<Button> bts)
{
    for (int i = 0; i < bts.size(); i++)
        visit[i][bts[i].status] = 1;
}

bool JudgeOver(vector<Button> bts)
{
    for (int i = 0; i < bts.size(); i++)
    {
        if (bts[i].status != 1)
            return false;
    }
    return true;
}

int main()
{
    queue<vector<Button>> bqueue;
    vector<Button> bts;
    int temp;
    for (int i = 0; i < 9; i++)
    {
        Button b;
        for (int j = 0; j < 5; j++)
        {
            cin >> temp;
            if (!j)
            {

                b.status = temp;
            }
            else
            {
                //赋值
                b.nums[j] = temp;
                visit[i][j] = 0;
            }
        }
        bts.push_back(b);
    }
    bqueue.push(bts);
    SetBtn(bts);
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
                tempbts.push_back(bts[j]);
            }

            tempbts[i].status++;
            if (tempbts[i].status == 5)
                tempbts[i].status = 1;
            int num = tempbts[i].nums[tempbts[i].status];
            tempbts[num].status++;
            if (tempbts[num].status == 5)
                tempbts[num].status = 1;
            if (Judge(tempbts)) //如果重复
                continue;
            tempbts[0].step++;
            if (JudgeOver(tempbts))
            {
                step = tempbts[0].step;
                break;
            }
            SetBtn(tempbts);
            bqueue.push(tempbts);
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