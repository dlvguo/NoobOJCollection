#include <iostream>
#include <time.h>
#include "simulation.h"
#include "characters.h"
#include "enums.h"
#include "fileio.h"
#include <cstdio>

using namespace std;

int main()
{
    while (true)
    {
        cout << "Please Cin pp k If PP==-1 Loop Over " << endl;
        int count = 500;
        int pp, k;
        cin >> pp >> k;
        Simulation::GetInstance()->InitSuccess();
        CharactersController::GetInstance()->SetP(pp, 10, 5, k);
        while (count--)
        {
            Simulation::GetInstance()->StartSimulation();
        }
        Simulation::GetInstance()->CoutSuccess();
        system("pause");
        system("cls");
    }

    //Map::GetInstance();
    //Characters::GetInstance()->AddCharacter(RUNNER);
    //Characters::GetInstance()->Move();
    // FileIO::SaveMap(Map::GetInstance());
    return 0;
}
