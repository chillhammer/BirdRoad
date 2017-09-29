#include <ncurses.h>
#include <unistd.h> //sleep
#include <fstream>
#include "GameMap.h"
#include "OtherVehicles.h"
#include "RandomGen.h"
#include "EntityManager.h"

using namespace std;

/*
    Singletons
    - gMap  (GameMap.h)
    - randGen  (RandomGen.h)
    - entManager (EntityManager.h)

*/

int main()
{
    initscr();
    curs_set(FALSE);

    long counter = 0;
    while(1) //Neverending Program
    {

        //Spawn Vehicles every so often
        if((counter++ % 10000) == 0)
            entManager->spawnVehicle();

        //Move all vehicles
        entManager->updateAll();

        //Draw all vehicles onto map
        entManager->drawAll();

        //Draw Map
        gMap->draw();

        //Refresh window with ncurses
        wrefresh(gMap->Window());
        refresh();
    }

    //end of program
    sleep(1);
    endwin();
    return 0;
}
