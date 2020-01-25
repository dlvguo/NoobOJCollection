#include <time.h>
#include <vector>
#include <string>
#include <queue>
#include "map.h"
#include "enums.h"
#include "fileio.h"
#include "distance.h"
using namespace std;

#ifndef _CHARACTERS_H_
#define _CHARACTERS_H_

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
    virtual void Move() = 0;

    //用于检测是否存活 若未存活则不执行一些移动等操作
    virtual bool Living();
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

bool Character::Living()
{
    if (type != Map::GetInstance()->GetGrid(pos_x, pos_y))
    {
        return false;
    }
    return true;
}

#pragma endregion

#pragma region ZOMBIE

class Zombie : public Character
{
private:
    int leftRate, rightRate, upRate, downRate;

public:
    //构造函数
    Zombie(DisplayType t, int x, int y, int l = 1, int r = 1, int u = 1, int d = 1);

    //移动
    void Move();
};

void Zombie::Move()
{
    Map *map = Map::GetInstance();
    int mapx = map->GetX();
    int mapy = map->GetY();

    //说明未置放
    if (pos_x == -1 && pos_y == -1)
    {
        for (int i = 0; i < mapy; i++)
        {
            if (map->CheckZoomieMotion(i, mapy - 1) == OK)
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
        if (!Living())
            return;
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
        Status s = map->CheckZoomieMotion(x1, y1);
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
            map->AddPNum(1);
        }
        map->UpdateMap(pos_x, pos_y, SPACE);
        pos_x = x1;
        pos_y = y1;
    }
}

Zombie::Zombie(DisplayType t, int x, int y, int l, int r, int u, int d) : Character(t, x, y)
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
    //当step==k 爆炸 炸到裤子都破掉
    int step;

public:
    //构造
    Plant(DisplayType type, int x, int y, int k = 4);
    ~Plant();
    //移动
    void Move();

    //爆炸
    void Boom();
};

Plant::Plant(DisplayType type, int x, int y, int k) : Character(type, x, y)
{
    this->k = k;
    step = 0;
}

void Plant::Move()
{
    if (!Living())
        return;
    step++;
    if (k == step)
    {
        Boom();
    }
}

void Plant::Boom()
{
    //干掉周围四周的地图
    for (int i = 0; i < 8; i++)
    {
        int x1 = pos_x + _DIRETION[i][0];
        int y1 = pos_y + _DIRETION[i][1];
        DisplayType s = Map::GetInstance()->GetGrid(x1, y1);
        if (s == ZOMBIE || s == ZOMBIE2 || s == RUNNER)
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

#pragma region Runner

class Runner : public Character
{
public:
    Runner(DisplayType type, int x, int y);

    //检测到各个地方路径
    void FigureDistance();

    //移动
    void Move();
};

Runner::Runner(DisplayType type, int x, int y) : Character(type, x, y){};

void Runner::Move()
{
    FigureDistance();
}

void Runner::FigureDistance()
{
    Map *map = Map::GetInstance();
    //初始化为-2 表示未访问
    int **steps;
    int mapx = map->GetX(), mapy = map->GetY();
    steps = new int *[mapx];
    for (int i = 0; i < mapx; i++)
    {
        steps[i] = new int[mapy];
        for (int j = 0; j < mapy; j++)
        {
            steps[i][j] = -2; //初始化step
        }
    }
    steps[pos_x][pos_y] = 0;

    queue<StepPosition> sposqueue;
    StepPosition spos(pos_x, pos_y);
    sposqueue.push(spos);
    while (!sposqueue.empty())
    {
        spos = sposqueue.front();
        sposqueue.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = spos.pos_x + _DIRETION[i][0];
            int y1 = spos.pos_y + _DIRETION[i][1];
            //避免越界
            if (x1 < 0 || y1 < 0 || x1 >= mapx || y1 >= mapy || steps[x1][y1] != -2)
                continue;
            //说明能到达第一列
            if (map->GetGrid(x1, y1) == BLOCK)
            {
                steps[x1][y1] = -1;
            }
            else
            {
                steps[x1][y1] = spos.step + 1;
                StepPosition s(x1, y1, steps[x1][y1]);
                sposqueue.push(s);
            }
        }
    }
#pragma region 输出Map
    for (int i = 0; i < mapx; i++)
    {
        for (int j = 0; j < mapy; j++)
        {
            if (j == 0)
                cout << "-";
            cout << "------"; //首先先定义每个横纵坐标循环后，输出---作为横格 //
        }
        cout << endl;
        for (int j = 0; j < mapy; j++)
        {
            if (j == 0)
                cout << "| "; //除了第一列有边界
            cout.width(3);
            cout << steps[i][j] << " | ";
        }
        cout << endl;
    }
    //在最后面输出下这个不就可以了
    for (int j = 0; j < mapy; j++)
    {
        if (j == 0)
            cout << "-";
        cout << "------"; //首先先定义每个横纵坐标循环后，输出---作为横格 //
    }

    //释放内存
    for (int i = 0; i < mapx; ++i)
        delete[] steps[i];
    delete[] steps;

#pragma endregion
}
#pragma endregion

#pragma region Characters

//代表角色控制器
class Characters
{
private:
    vector<Character *> charactersVector;
    int pp = 2, pz = 10, py = 5, limitZoobile = 10, zoobileNum = 0; //限制僵尸数量
    //初始化的时候根据数量放置僵尸 并且未放置的时候x=-1 y=-1
    Characters(int pNum = 3, int zNum = 3, int rNum = 0, int plantNum = 0)
    {
        zoobileNum = pNum + zNum;
        //初始化放置3个
        while (pNum--)
        {
            Zombie *z = new Zombie(ZOMBIE2, -1, -1, 2, 1, 1, 1);
            charactersVector.push_back(z);
        }

        while (zNum--)
        {
            Zombie *z = new Zombie(ZOMBIE, -1, -1, 2, 1, 1, 1);
            charactersVector.push_back(z);
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

    //去除死亡的角色 名字可能需要更改
    void RemoveCharacters();

    //随机创建角色
    void SRandCharacter();

    //设置概率
    void SetP(int pp, int pz, int py);
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
    if (t == ZOMBIE)
    { //1号僵尸
        y1 = Map::GetInstance()->GetY() - 1;
        if (Map::GetInstance()->GetGrid(x1, y1) == SPACE)
        {
            Zombie *z = new Zombie(t, x1, y1, 2, 1, 1, 1);
            Map::GetInstance()->UpdateMap(x1, y1, t);
            charactersVector.push_back(z);
            zoobileNum++;
        }
    }
    else if (t == ZOMBIE2)
    {
        y1 = Map::GetInstance()->GetY() - 1;
        if (Map::GetInstance()->GetGrid(x1, y1) == SPACE)
        {
            zoobileNum++;
            Zombie *z = new Zombie(t, x1, y1, 4, 1, 1, 1);
            Map::GetInstance()->UpdateMap(x1, y1, t);
            charactersVector.push_back(z);
        }
    }
    else if (t == RUNNER)
    {
        y1 = Map::GetInstance()->GetY() - 1;
        if (Map::GetInstance()->GetGrid(x1, y1) == SPACE)
        {
            zoobileNum++;
            Runner *r = new Runner(t, x1, y1);
            Map::GetInstance()->UpdateMap(x1, y1, t);
            charactersVector.push_back(r);
        }
    }
    else if (t == PLANT)
    {
        y1 = rand() % (Map::GetInstance()->GetY() / 2) + 1;
        if (Map::GetInstance()->GetGrid(x1, y1) == SPACE)
        {
            Plant *p = new Plant(t, x1, y1);
            Map::GetInstance()->UpdateMap(x1, y1, t);
            charactersVector.push_back(p);
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
    for (int i = 0; i < charactersVector.size(); i++)
    {
        charactersVector[i]->Move();
    }

    //如果角色的DisPlayType不一样说明出事了于是
    RemoveCharacters();
}

void Characters::RemoveCharacters()
{
    auto iter = charactersVector.begin();
    while (iter != charactersVector.end())
    {
        //判断是否删除僵尸
        if (!(*iter)->Living())
        {
            if ((*iter)->type == ZOMBIE || (*iter)->type == ZOMBIE2)
            {
                zoobileNum--;
            }
            delete *iter;
            iter = charactersVector.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
}

void Characters::SRandCharacter()
{
    int p = rand() % 100;
    string str = "p:" + std::to_string(p);
    FileIO::AppFile(str);
    if (p < pp)
    {
        AddCharacter(PLANT);
    }
    else if (p < pp + pz)
    {
        if (zoobileNum < limitZoobile)
            AddCharacter(ZOMBIE);
    }
    else if (p < pp + pz + pz)
    {
        if (zoobileNum < limitZoobile)
            AddCharacter(ZOMBIE2);
    }
}

void Characters::SetP(int pp, int pz, int py)
{
    this->pp = pp;
    this->pz = pz;
    this->py = py;
}
#pragma endregion

#endif
