#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "BaseGameEntity.h"
#include <vector>
//shorthand
#define entManager EntityManager::Instance()


//singleton object
class EntityManager{
private:
    EntityManager();
    std::vector<BaseGameEntity*> entMap;
public:
    ~EntityManager();


    static EntityManager* Instance();
    void spawnVehicle();
    void registerEntity(BaseGameEntity*);
    void updateAll();
    void drawAll();

    bool checkPosition(Vector2D);

};

#endif
