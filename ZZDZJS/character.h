

#include <time.h>
#include <vector>
#include "map.h"
#include "enums.h"
using namespace std;

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#pragma region Character
class Character
{

public:
    DisplayType type;
    int pos_x, pos_y;

    Character(DisplayType type, int x, int y);

    //获取pos_X
    int GetX();

    //获取pos_y
    int GetY();

    //角色移动
    virtual void Move(){};
};

Character::Character(DisplayType type, int x, int y)
{
    this->type = type;
    this->pos_x = x;
    this->pos_y = y;
}

int Character::GetX()
{
    return this->pos_x;
}

int Character::GetY()
{
    return this->pos_y;
}

#pragma endregion

#pragma region ZOOBIE

class Zoobil : public Character
{
private:
    int leftRate, rightRate, upRate, downRate;

public:
    //构造函数
    Zoobil(DisplayType t, int x, int y, int l = 1, int r = 1, int u = 1, int d = 1);

    //移动
    void Move();
};

void Zoobil::Move()
{
    if (type == OVER)
        return;
    Map *map = Map::GetInstance();
    int mapx = map->GetX();
    int mapy = map->GetY();

    //说明未置放
    if (pos_x == -1 && pos_y == -1)
    {
        for (int i = 0; i < mapy; i++)
        {
            if (map->Check(i, mapy - 1) == OK)
            {
                map->UpdateMap(i, mapy - 1, type);
                pos_x = i;
                pos_y = mapy - 1;
                break;
            }
        }
    }
    else
    {
        //假设只有 a和b
        int total = leftRate + rightRate + upRate + downRate;
        int pos = rand() % total;
        int x1 = pos_x, y1 = pos_y;
        //说明左边移动
        if (pos < leftRate)
        {
            x1 -= 1;
        }
        //右边移动
        else if (pos < leftRate + rightRate)
        {
            x1 += 1;
        }
        else if (pos < leftRate + rightRate + upRate)
        {
            y1 += 1;
        }
        else
        {
            y1 -= 1;
        }
        Status s = map->Check(x1, y1);
        if (s == ERROR)
            return;
        //如果新的位置能放置
        if (s == OK)
        {
            //更新地图 并把原来坐标更新
            map->UpdateMap(x1, y1, type);
        }
        else if (s == HITGOAL)
        {
            map->UpdateMap(x1, y1, OVER);
        }
        else if (s == HITPLANT)
        {
            map->UpdateMap(x1, y1, type);
            //吃到植物++
            map->AddPnum(1);
        }
        map->UpdateMap(pos_x, pos_y, SPACE);
        pos_x = x1;
        pos_y = y1;
    }
}

Zoobil::Zoobil(DisplayType t, int x, int y, int l, int r, int u, int d) : Character(t, x, y)
{
    this->leftRate = l;
    this->rightRate = r;
    this->upRate = u;
    this->downRate = d;
}

#pragma endregion

#pragma region Plant

class Plant : public Character
{
private:
    int k;

public:
    //八方图的方向
    static int direction[8][2];

    //构造
    Plant(DisplayType type, int x, int y);
    ~Plant();
    //移动
    void Move();

    //爆炸
    void Boom();
};

int Plant::direction[8][2] = {1, 0, 1, -1, 1, 1, 0, 1, 0, -1, -1, 0, -1, 1, -1, -1};

Plant::Plant(DisplayType type, int x, int y) : Character(type, x, y)
{
    k = 0;
}

Plant::~Plant()
{
}

void Plant::Move()
{
    k++;
    if (k == 4)
    {
        Boom();
    }
}

void Plant::Boom()
{
    //干掉周围四周的地图
    for (int i = 0; i < 8; i++)
    {
        int x1 = pos_x + direction[i][0];
        int y1 = pos_y + direction[i][1];
        DisplayType s = Map::GetInstance()->GetGrid(x1, y1);
        if (s == ZOOBIE || s == ZOOBIE2)
        {
            //更新地图
            Map::GetInstance()->UpdateMap(x1, y1, SPACE);
            //轰炸数量++
            Map::GetInstance()->AddZNum(1);
        }
    }
    Map::GetInstance()->UpdateMap(pos_x, pos_y, SPACE);
}
#pragma endregion

#pragma region Characters

//代表角色控制器
class Characters
{
private:
    vector<Plant> plants;
    vector<Zoobil> zoobils;
    int PP = 2, PZ = 10, PY = 5;

    //初始化的时候根据数量放置僵尸 并且未放置的时候x=-1 y=-1
    Characters(int pNum = 3, int zNum = 3, int rNum = 0, int plantNum = 0)
    {
        //初始化放置3个
        while (pNum--)
        {
            Zoobil z(ZOOBIE2, -1, -1, 2, 1, 1, 1);
            zoobils.push_back(z);
        }

        while (zNum--)
        {
            Zoobil z(ZOOBIE, -1, -1, 2, 1, 1, 1);
            zoobils.push_back(z);
        }
    }
    //俩种僵尸数量
public:
    //单例模式 方便交互
    static Characters *GetInstance();

    //添加角色
    void AddCharacter(DisplayType t);

    //所有角色移动
    void Move();

    //去除死亡的角色
    void SelectChartes();

    //随机创建角色
    void SRandCharacter();
};

Characters *Characters::GetInstance()
{
    static Characters instance; //局部静态变量
    return &instance;
}

void Characters::AddCharacter(DisplayType t)
{
    int x1 = rand() % Map::GetInstance()->GetX();
    int y1;
    if (t == ZOOBIE)
    { //1号僵尸
        y1 = Map::GetInstance()->GetY() - 1;
        if (Map::GetInstance()->GetGrid(x1, y1) == SPACE)
        {
            Zoobil z(t, x1, y1, 2, 1, 1, 1);
            Map::GetInstance()->UpdateMap(x1, y1, t);
            zoobils.push_back(z);
        }
    }
    else if (t == ZOOBIE2)
    {
        y1 = Map::GetInstance()->GetY() - 1;
        if (Map::GetInstance()->GetGrid(x1, y1) == SPACE)
        {

            Zoobil z(t, x1, y1, 4, 1, 1, 1);
            Map::GetInstance()->UpdateMap(x1, y1, t);
            zoobils.push_back(z);
        }
    }
    else if (t == PLANT)
    {
        y1 = rand() % (Map::GetInstance()->GetY() / 2) + 1;
        if (Map::GetInstance()->GetGrid(x1, y1) == SPACE)
        {
            Plant p(t, x1, y1);
            Map::GetInstance()->UpdateMap(x1, y1, t);
            plants.push_back(p);
        }
    }
    //待做
    else
    {
    }
}

void Characters::Move()
{
    //TODO 计数位置
    for (int i = 0; i < zoobils.size(); i++)
    {
        zoobils[i].Move();
    }

    for (int i = 0; i < plants.size(); i++)
    {
        plants[i].Move();
    }

    //如果角色的DisPlayType不一样说明出事了于是
    SelectChartes();
}

void Characters::SelectChartes()
{
    auto iter = plants.begin();
    while (iter != plants.end())
    {
        if (iter->type != Map::GetInstance()->GetGrid(iter->GetX(), iter->GetY()))
        {
            iter = plants.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    auto iter2 = zoobils.begin();
    while (iter2 != zoobils.end())
    {
        if (iter2->type != Map::GetInstance()->GetGrid(iter2->GetX(), iter2->GetY()))
        {
            iter2 = zoobils.erase(iter2);
        }
        else
        {
            ++iter2;
        }
    }
}

void Characters::SRandCharacter()
{
    int p = rand() % 100;
    if (p < PP)
    {
        AddCharacter(PLANT);
    }
    else if (p < PP + PZ)
    {
        AddCharacter(ZOOBIE);
    }
    else if (p < PP + PZ + PY)
    {
        AddCharacter(ZOOBIE2);
    }
}
#pragma endregion

#endif
