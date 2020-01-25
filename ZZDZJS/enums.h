#ifndef _ENUMS_H_
#define _ENUMS_H_

enum Status
{
    ERROR = 0,
    OK = 1,
    HITGOAL = 2,
    HITPLANT = 3
};

enum DisplayType
{
    BLOCK = 0,   //#
    SPACE = 1,   //' '
    GOAL = 2,    //G
    OVER = 3,    //O
    ZOOBIE = 4,  //Z僵尸1号
    ZOOBIE2 = 5, //Y僵尸2号
    PLANT = 6,   //P 植物
    RUNNER = 7   //R RunNer
};

//八方向
enum Diretion
{
    LEFT = 0,
    RIGHT,
    UP,
    DOWN,
    LEFTUP,
    LEFTDOWN,
    RIGHTUP,
    RIGHUTDOWN
};
#endif
