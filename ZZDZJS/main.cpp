#include <iostream>
#include <time.h>
#include "simulation.h"
#include "character.h"
#include "enums.h"
using namespace std;

int main()
{

    Simulation::GetInstance()->StartSimulation();
    return 0;
}
