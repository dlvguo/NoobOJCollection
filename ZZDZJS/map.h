#include <iostream>
#include <time.h>
#include "enums.h"
#include <queue>
#include "distance.h"
using namespace std;

#ifndef _MAP_H_
#define _MAP_H_

class Map
{
private:
    int **grid; //地图绘制
    int y;      //定义y轴列数
    int x;      //定义x轴行数
    int roundNum;
    int zNum;
    int pNum;

    Map(int x = 6, int y = 12) //构造函数是私有的
    {
        this->y = y;
        this->x = x;
        this->roundNum = 0;
        this->zNum = 0;
        this->pNum = 0;
        InitMap();
    }

public:
    //单例模式 方便交互
    static Map *GetInstance();

    //析构函数 释放内存  a
    ~Map();

    //设定自定义范围
    void SetDefineMap();

    //初始化地图包含放置东西
    void InitMap();

    //创造空的地图
    void CreateEmptyMap();

    //放置G
    void G_PlaceMent();

    //放置函数
    void Place_Block(int num);

    //获取XY
    Status GetXY(int x, int y);

    //判断僵尸行为
    Status CheckZoomieMotion(int x, int y);

    //DisPlay
    void DisPlay(bool isClear = true);
    //更新地图
    void UpdateMap(int x, int y, DisplayType t);
    //获取地图行
    int GetX();
    //检查格子放置的位置
    void Place();

    //获取地图列
    int GetY();
    //获取回合数
    int GetRound();
    //增加回合数
    void AddRound(int num);
    //获取植物数量
    int GetPNum();
    //增加植物数量
    void AddPNum(int num);
    //获取僵尸数量
    int GetZNum();
    //增加僵尸数量
    void AddZNum(int num);
    //获取grid的type
    DisplayType GetGrid(int x, int y);
    //使用BFS进行判断
    bool JudgePass(); //判断是否
};

//释放Map
Map::~Map()
{
    for (int i = 0; i < this->x; ++i)
        delete[] grid[i];
    delete[] grid;
};

Map *Map::GetInstance()
{
    static Map instance; //局部静态变量
    return &instance;
}

void Map::SetDefineMap()
{
    cout << "Please enter the width of the map: " << endl;
    cin >> x;
    cout << "Please enter the length of the map: " << endl;
    cin >> y;
    CreateEmptyMap();
};

void Map::InitMap()
{
    bool tag = false; //false代表地图不成功 true地图成功
    while (true)
    {
        CreateEmptyMap();
        G_PlaceMent();
        Place_Block(15);
        //DisPlay(false);
        tag = JudgePass();
        if (tag == true)
            break;
    }
}

void Map::CreateEmptyMap()
{
    //避免越界
    x = x < 1 ? 1 : x;
    if (x < 1)
        x = 1;
    y = y < 4 ? 4 : y;
    //可删上面
    if (y < 4)
        y = 4;

    //二级指针赋值法 等同grid[w][l]
    grid = new int *[x];
    for (int i = 0; i < x; i++)
    {
        grid[i] = new int[y];
        for (int j = 0; j < y; j++)
        {
            grid[i][j] = SPACE; //初始化空格
        }
    }
};

void Map::G_PlaceMent()
{
    for (int i = 0; i < x; i++)
    {
        grid[i][0] = GOAL;
    }
}

void Map::Place_Block(int num)
{
    srand(time(NULL));
    int limit = 2; //避免进入0、1

    //放置
    while (num)
    {
        int x1 = (rand() % x);
        //int y1 = (rand() % (y - limit-1)) + limit;
        int y1 = (rand() % y);
        if (GetXY(x1, y1) && grid[x1][y1] == SPACE)
        {
            grid[x1][y1] = BLOCK;
            num--;
        }
    }
}

void Map::Place()
{
    int x1, y1;
    while (1)
    {
        x1 = (rand() % x);
        y1 = (rand() % y);
        if (grid[x1][y1] == SPACE)
        {
            break;
        }
    }
    //TODO 
}

Status Map::GetXY(int x, int y)
{
    if (x < 0 || x >= this->x || y < 2 || y >= this->y - 1)
        return ERROR;
    return OK;
}

void Map::DisPlay(bool isClear)
{
    if (isClear)
        system("cls");

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            //在每一列第一行多输出一个 | - |
            if (j == 0)
                cout << "-";
            cout << "----"; //首先先定义每个横纵坐标循环后，输出---作为横格 //
        }
        cout << endl;
        for (int j = 0; j < y; j++)
        {
            if (j == 0)
                cout << "| "; //除了第一列有边界
            char ch = ' ';
            //根据不同枚举输出不同类型
            if (grid[i][j] == SPACE)
            {
                ch = ' ';
            }
            else if (grid[i][j] == BLOCK)
            {
                ch = '#';
            }
            else if (grid[i][j] == GOAL)
            {
                ch = 'G';
            }
            else if (grid[i][j] == ZOMBIE)
            {
                ch = 'Z';
            }
            else if (grid[i][j] == ZOMBIE2)
            {
                ch = 'Y';
            }
            else if (grid[i][j] == PLANT)
            {
                ch = 'P';
            }
            else if (grid[i][j] == OVER)
            {
                ch = 'O';
            }
            else if (grid[i][j] == RUNNER)
            {
                ch = 'R';
            }
            else //保留项
            {
                ch = ' ';
            }
            cout << ch << " | ";
        }
        cout << endl;
    }
    //在最后面输出下这个不就可以了
    for (int j = 0; j < y; j++)
    {
        if (j == 0)
            cout << "-";
        cout << "----"; //首先先定义每个横纵坐标循环后，输出---作为横格 //
    }

    cout << endl
         << "Round:" << roundNum << "\t\tZ:" << zNum << "\t\tP:" << pNum << endl;
}


Status Map::CheckZoomieMotion(int x, int y)
{
    //判断边界
    if (x < 0 || x >= this->x || y < 0 || y >= this->y)
        return ERROR;
    //如果grid[x][y]==GOAL
    if (grid[x][y] == GOAL)
        return HITGOAL;
    //如果' '
    else if (grid[x][y] == SPACE)
        return OK;
    //如果PLANT
    else if (grid[x][y] == PLANT)
        return HITPLANT;
    return ERROR;
}

int Map::GetX()
{
    return this->x;
}

int Map::GetY()
{
    return this->y;
}

void Map::UpdateMap(int x, int y, DisplayType t)
{
    if (x < 0 || x >= this->x || y < 0 || y >= this->y)
        return;
    grid[x][y] = t;
}

void Map::AddRound(int num)
{
    this->roundNum += num;
}

void Map::AddPNum(int num)
{
    this->pNum += num;
}

void Map::AddZNum(int num)
{
    this->zNum += num;
}

DisplayType Map::GetGrid(int x, int y)
{
    //防止超界
    if (x < 0 || x >= this->x)
        x = 0;
    if (y < 0 || y >= this->y)
        y = 0;
    return (DisplayType)grid[x][y];
}

int Map::GetRound()
{
    return roundNum;
}

int Map::GetPNum()
{
    return pNum;
}

int Map::GetZNum()
{
    return zNum;
}

bool Map::JudgePass()
{
    //这一部分用来存放是否通过
    int **visit;
    visit = new int *[x];
    for (int i = 0; i < x; i++)
    {
        visit[i] = new int[y];
        for (int j = 0; j < y; j++)
        {
            visit[i][j] = 0; //初始化空格
        }
    }
    visit[0][y - 1] = 1;

    queue<Position> posqueue;
    Position p(0, y - 1);
    posqueue.push(p);
    while (!posqueue.empty())
    {
        p = posqueue.front();
        posqueue.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = p.pos_x + _DIRETION[i][0];
            int y1 = p.pos_y + _DIRETION[i][1];
            //避免越界
            if (x1 < 0 || y1 < 0 || x1 >= x || y1 >= y || visit[x1][y1])
                continue;
            visit[x1][y1] = 1;
            //说明能到达第一列
            if (y1 == 0)
                return true;
            else if (grid[x1][y1] != BLOCK)
            {
                Position t(x1, y1);
                posqueue.push(t);
            }
        }
    }
    return false;
}

#endif
