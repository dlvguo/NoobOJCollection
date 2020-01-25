#ifndef _CHARACTER_H_
#define _CHARACTER_H_

//分别对应                      左       右      上      下       左上     左下     右上      右下
const int _DIRETION[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

struct Position
{
    int pos_x, pos_y;
    Position(int x, int y)
    {
        pos_x = x;
        pos_y = y;
    }
};


struct StepPosition
{
    int pos_x, pos_y, step;
    StepPosition(int x, int y, int step = 0)
    {
        pos_x = x;
        pos_y = y;
        this->step = step;
    }
};

#endif