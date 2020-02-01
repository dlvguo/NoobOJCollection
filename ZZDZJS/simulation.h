#include <iostream>
#include <conio.h>
#include "map.h"
#include "characters.h"
using namespace std;

#ifndef _SIMULATION_H_
#define _SIMULATION_H_

class Simulation
{
private:
    Simulation() {}
    Map *map;
    CharactersController *charactersCtrl;
    int roundNum, pNum, zNum, success = 0, unsuccess = 0; //回合数 植物数 僵尸数 成功次数 失败次数

public:
    //单例 SingleMode
    static Simulation *GetInstance();

    //开始模拟
    void StartSimulation();

    //执行一次
    void ActionOnce();

    //判断结束
    Status JudgeOver();
    //初始化胜率
    void InitSuccess();

    //输出成功概率
    void CoutSuccess();
};

Simulation *Simulation::GetInstance()
{
    static Simulation instance; //局部静态变量
    return &instance;
}

void Simulation::InitSuccess()
{
    success = 0;
    unsuccess = 0;
}

void Simulation::CoutSuccess()
{
    cout<<"SuccessCount:"<<success<<" UnSuccessCout::"<<unsuccess<<endl;
}

void Simulation::StartSimulation()
{
    srand(time(NULL));
    map = Map::GetInstance();
    charactersCtrl = CharactersController::GetInstance();
    ActionOnce(); //TODO
    char c;
    while (true)
    {
        // c = getch();
        // if (c == ' ')
        // {
            ActionOnce();
        // }
        // else if (c == 'q')
        // {
        //     break;
        // }
        // else if (c == 'r')
        // {
        //     CharactersController::GetInstance()->AddCharacter(RUNNER);
        // }
        //判断是否OVER
        if (JudgeOver() == OK)
        {
            break;
        }
    }
}

void Simulation::ActionOnce()
{
    charactersCtrl->Move();
    map->AddRound(1);
    //map->DisPlay();
    //if(map->GetRound()%10==0)
    charactersCtrl->SRandCharacter();
}

Status Simulation::JudgeOver()
{
    if (map->GetRound() >= 10000)
    {
        success++;
        return OK;
    }
    for (int i = 0; i < map->GetX(); i++)
    {
        if (map->GetGrid(i, 0) != OVER)
            return ERROR;
    }
    unsuccess++;
    return OK;
}

#endif
