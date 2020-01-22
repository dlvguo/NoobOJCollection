#include <iostream>
#include <conio.h>
#include "map.h"
#include "character.h"
using namespace std;

#ifndef _SIMULATION_H_
#define _SIMULATION_H_

class Simulation
{
private:
    Simulation() {}
    Map *map;
    Characters *characters;
    int roundNum, pNum, zNum; //回合数 植物数 僵尸数

public:
    //单例 SingleMode
    static Simulation *GetInstance();

    //开始模拟
    void StartSimulation();

    //执行一次
    void ActionOnce();

    //判断结束
    Status JudgeOver();
};

Simulation *Simulation::GetInstance()
{
    static Simulation instance; //局部静态变量
    return &instance;
}

void Simulation::StartSimulation()
{
    srand(time(NULL));
    map = Map::GetInstance();
    characters = Characters::GetInstance();
    ActionOnce(); //TODO
    char c;
    while (true)
    {
        c = getch();
        if (c == ' ')
        {
            ActionOnce();
        }
        else if (c == 'q')
        {
            break;
        }
        //判断是否OVER
        if (JudgeOver() == OK)
        {
            break;
        }
    }
}

void Simulation::ActionOnce()
{
    characters->Move();
    map->AddRound(1);
    map->DisPlay();
    //if(map->GetRound()%10==0)
    characters->SRandCharacter();
}

Status Simulation::JudgeOver()
{
    if (map->GetRound() >= 10000)
        return OK;
    for (int i = 0; i < map->GetX(); i++)
    {
        if (map->GetGrid(i, 0) != OVER)
            return ERROR;
    }
    return OK;
}

#endif
