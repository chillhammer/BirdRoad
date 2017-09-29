#include <fstream>
#include <ncurses.h>
#include "GameMap.h"
#include "RandomGen.h"
#include "Road.h"
#include "Avenue.h"

//Constructor
GameMap::GameMap(){
    win = newwin(FILE_HEIGHT,FILE_WIDTH,0,(COLS-FILE_WIDTH)/2);

    //lanes
    //roads (entrance, exit, intersecion, init dir)
    roads[0] = Road(Vector2D(0,12), Vector2D(58,12), 4, 0);
    roads[1] = Road(Vector2D(58,8), Vector2D(0,8), 4, 180);

    avenues[0] = Avenue(Vector2D(5,0), Vector2D(5,19), 7, 90);
    avenues[1] = Avenue(Vector2D(27,0), Vector2D(27,19), 7, 90);
    avenues[2] = Avenue(Vector2D(49,0), Vector2D(49,19), 7, 90);

    avenues[3] = Avenue(Vector2D(8,19), Vector2D(8,0), 15, 270);
    avenues[4] = Avenue(Vector2D(30,19), Vector2D(30,0), 15, 270);
    avenues[5] = Avenue(Vector2D(52,19), Vector2D(52,0), 15, 270);
}

//Destructor
GameMap::~GameMap(){

}

//returns static instace
GameMap* GameMap::Instance(){
    GameMap static gm;
    return &gm;
}

//draw character
void GameMap::drawChar(double x, double y, char model){
    if(x <= mapWidth() && y <= mapHeight())
        mvwaddch(gMap->Window(),static_cast<int>(y+1),static_cast<int>(x+1),model);
}

//draw game map background
void GameMap::draw(){
    std::ifstream backgroundFile;
    backgroundFile.open("BirdRoad.txt");
    int yrender = 0;
    int xrender = 0;
    while(backgroundFile){
        std::string line;
        getline(backgroundFile,line);
        //draw character if not empty
        for(int i = 0; i<line.length(); i++){
            if(line[i]!= ' ')
                mvwaddch(win, yrender,i,line[i]);
        }
        yrender++;
    }
    wrefresh(win);
}

//get lanes random or manual
Road GameMap::getRoad(){
    return roads[randGen->rInt(ROAD_AMOUNT)];
}

Road GameMap::getRoad(int l){
    return roads[l];
}

Avenue GameMap::getAvenue(){
    return avenues[randGen->rInt(AVENUE_AMOUNT)];
}

Avenue GameMap::getAvenue(int l){
    return avenues[l];
}

