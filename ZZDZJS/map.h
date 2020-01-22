#include <iostream>
#include <time.h>
#include "enums.h"
using namespace std;

#ifndef _MAP_H_
#define _MAP_H_

class Map
{
private:
    int **grid; //地图绘制
    int y;      //定义y轴行数
    int x;      //定义x轴列数
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
        CreateEmptyMap();
        G_PlaceMent();
        Place_Block(15);
    }

public:
    //单例模式 方便交互
    static Map *GetInstance()
    {
        static Map instance; //局部静态变量
        return &instance;
    }

    //析构函数 释放内存  a
    ~Map();

    //设定自定义范围
    void SetDefineMap();

    //创造空的地图
    void CreateEmptyMap();

    //放置G
    void G_PlaceMent();

    //放置函数
    void Place_Block(int num);

    //获取XY
    Status GetXY(int x, int y);

    //判断是否能放置
    Status Check(int x, int y);

    //DisPlay
    void DisPlay();
    //更新地图
    void UpdateMap(int x, int y, DisplayType t);
    //获取地图行
    int GetX();
    //获取地图列
    int GetY();
    //增加回合数
    void AddRound(int num);
    void AddZNum(int num);
    void AddPnum(int num);
    //获取回合数
    int GetRound();

    DisplayType GetGrid(int x, int y);
};

//释放Map
Map::~Map()
{
    for (int i = 0; i < this->x; ++i)
        delete[] grid[i];
    delete[] grid;
};

void Map::SetDefineMap()
{
    cout << "Please enter the width of the map: " << endl;
    cin >> x;
    cout << "Please enter the length of the map: " << endl;
    cin >> y;
    CreateEmptyMap();
};

void Map::CreateEmptyMap()
{
    //避免越界
    x = x < 1 ? 1 : x;
    y = y < 4 ? 4 : y;
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

Status Map::GetXY(int x, int y)
{
    if (x < 0 || x >= this->x || y < 2 || y >= this->y - 1)
        return (Status)ERROR;
    return (Status)OK;
}

void Map::DisPlay()
{
    system("cls");

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
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
            else if (grid[i][j] == ZOOBIE)
            {
                ch = 'Z';
            }
            else if (grid[i][j] == ZOOBIE2)
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
            else
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

Status Map::Check(int x, int y)
{
    if (x < 0 || x >= this->x || y < 0 || y >= this->y)
        return ERROR;
    if (grid[x][y] == GOAL)
        return HITGOAL;
    else if (grid[x][y] == SPACE)
        return OK;
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

void Map::AddPnum(int num)
{
    this->pNum += num;
}

void Map::AddZNum(int num)
{
    this->zNum += num;
}

DisplayType Map::GetGrid(int x, int y)
{
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

#endif
