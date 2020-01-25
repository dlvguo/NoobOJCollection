#include <iostream>
#include <time.h>
#include "simulation.h"
#include "characters.h"
#include "enums.h"
#include "fileio.h"
using namespace std;

int main()
{
    
    Simulation::GetInstance()->StartSimulation();
    //Map::GetInstance();
    //Characters::GetInstance()->AddCharacter(RUNNER);
    //Characters::GetInstance()->Move();
    // FileIO::SaveMap(Map::GetInstance());
    system("pause");
    return 0;
}
