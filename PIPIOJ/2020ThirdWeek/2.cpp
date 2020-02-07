#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
char Map[1001][1001];
int pipisteps[1001][1001] = {0};
int poposteps[1001][1001] = {0};

int M, N;
const int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, -1, 1, 1, -1, 1, -1, -1};

struct Pos
{
    //step 代表回合
    int x, y, step;
    Pos(int _x = 0, int _y = 0, int _step = 0)
    {
        x = _x;
        y = _y;
        step = _step;
    }
};

int main()
{
    cin >> N >> M;
    queue<Pos> popoPos;  //POPO Pos queue
    queue<Pos> pipiPos;  //PIPI Pos queue
    queue<Pos> tempPipi; //临时存放4个PIPI

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Map[i][j];
            poposteps[i][j] = 0;
            pipisteps[i][j] = 0;
            if (Map[i][j] == 'D')
            {
                Pos p(i, j, 0);
                pipiPos.push(p);
                pipisteps[i][j] = -1;
            }
            else if (Map[i][j] == 'C')
            {
                Pos p(i, j, 0);
                popoPos.push(p);
                poposteps[i][j] = -1;
            }
        }
    }
    int step = 0, firstStep;
    Pos p;
    //应该是把每一圈都走过去 而不是一个走过去
    while (!popoPos.empty() || !pipiPos.empty())
    {
        if (step)
            break;
        //代表第一个p
        p = pipiPos.front();
        firstStep = p.step;
        while (!pipiPos.empty() && step == 0)
        {
            //获取第一个
            p = pipiPos.front();
            if (firstStep != p.step) //同一轮都解决
                break;
            pipiPos.pop(); //PIPI先走第一步
            for (int i = 0; i < 4; i++)
            {
                int x1 = p.x + dir[i][0], y1 = p.y + dir[i][1];
                if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= M || pipisteps[x1][y1] || Map[x1][y1] == '#')
                    continue;
                if (poposteps[x1][y1] || Map[x1][y1] == 'C')
                {
                    step = p.step + 1;
                    break;
                }
                pipisteps[x1][y1] = p.step + 1;
                Pos temp(x1, y1, p.step + 1);
                //放入临时PIPI再走
                tempPipi.push(temp);
            }
            //放入的四个再走4步？
            while (!tempPipi.empty() && step == 0)
            {
                //临时Pipi消除
                p = tempPipi.front();
                tempPipi.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x1 = p.x + dir[i][0], y1 = p.y + dir[i][1];
                    if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= M || pipisteps[x1][y1] || Map[x1][y1] == '#')
                        continue;
                    if (poposteps[x1][y1] || Map[x1][y1] == 'C')
                    {
                        //这时候是同一回合
                        step = p.step;
                        break;
                    }
                    pipisteps[x1][y1] = p.step;
                    Pos temp(x1, y1, p.step);
                    //放入临时PIPI再走
                    pipiPos.push(temp);
                }
            }
        }
        if (step)
            break;

        //PoPo八方向
        p = popoPos.front();
        firstStep = p.step;
        while (!popoPos.empty() && step == 0)
        {
            p = popoPos.front();
            if (p.step != firstStep)
                break;
            popoPos.pop();
            for (int i = 0; i < 8; i++)
            {
                int x1 = p.x + dir[i][0], y1 = p.y + dir[i][1];
                if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= M || poposteps[x1][y1] || Map[x1][y1] == '#')
                    continue;
                if (pipisteps[x1][y1] || Map[x1][y1] == 'D')
                {
                    step = p.step + 1;
                    break;
                }
                poposteps[x1][y1] = p.step + 1;
                Pos temp(x1, y1, p.step + 1);
                //放入临时PIPI再走
                popoPos.push(temp);
            }
        }
    }
    if (step == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl
             << step << endl;
    }
}