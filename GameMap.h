#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <ncurses.h>
#include "Road.h"
#include "Avenue.h"

//shorthand
#define gMap GameMap::Instance()

//singleton object
class GameMap{
private:
    static int const FILE_WIDTH = 62;
    static int const FILE_HEIGHT = 21;

    static int const ROAD_AMOUNT = 2;
    static int const AVENUE_AMOUNT = 6;
    GameMap();
    WINDOW* win;
    Road roads[ROAD_AMOUNT];
    Avenue avenues[AVENUE_AMOUNT];


public:
    ~GameMap();


    static GameMap* Instance();
    void draw();
    void drawChar(double,double,char);
    WINDOW* Window(){return win;}
    int mapWidth(){return FILE_WIDTH-2;} //2 for the borders
    int mapHeight(){return FILE_HEIGHT-2;} //2 for the borders

    Road getRoad();
    Avenue getAvenue();

    Road getRoad(int);
    Avenue getAvenue(int);
};

#endif
