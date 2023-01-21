#ifndef _INPUT_
#define _INPUT_

#include "../Components/IComponent.hpp"
#include <raylib.h>
#include "../Entity/Player.hpp"
#include "../Entity/Projectiles.hpp" 
#include <iostream>
#include "../Factory/ProjectilesFactory.hpp"
#include "./Keys.hpp"
#include "./ScreenSize.hpp"
#include "./Audio.hpp"

class Input
{
private:

public:
    Input(/* args */);
    ~Input();
    void handler(Player *player, std::vector<Projectiles *> &projectiles, std::unique_ptr<Factory> &projectileFactory, ScreenSize screenSize, Audio &audio);
};

#endif