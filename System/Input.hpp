#ifndef _INPUT_
#define _INPUT_

#include "../Components/IComponent.hpp"
#include <raylib.h>
#include "../Entity/Player.hpp"
#include "../Entity/Projectiles.hpp" 
#include <iostream>
#include "../Factory/ProjectilesFactory.hpp"
#include "./Keys.hpp"

class Input
{
private:

public:
    Input(/* args */);
    Input(int keyUp, int keyRight, int keyDown, int keyLeft);
    ~Input();
    void handler(Player *player, std::vector<Projectiles *> *projectiles, std::unique_ptr<Factory> &projectileFactory);
};

#endif