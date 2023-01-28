#ifndef _INPUT_
#define _INPUT_

#include <raylib.h>
#include <iostream>
#include "../Components/IComponent.hpp"
#include "../Factory/ProjectilesFactory.hpp"
#include "../Entity/Projectiles.hpp" 
#include "../Entity/Player.hpp"
#include "./ScreenSize.hpp"
#include "./Audio.hpp"
#include "./Keys.hpp"

class Input
{
private:

public:
    Input(/* args */);
    ~Input();
    void handler(Player *player, std::vector<Projectiles *> &projectiles, std::unique_ptr<Factory> &projectileFactory, ScreenSize screenSize, Audio &audio);
    bool isInRect(Rectangle rect);
    bool isClicked(Rectangle rect);
    bool isKeyPressed(int key);
    bool isKeyDown(int key);
    bool checkCollisionPointRec(Vector2 point, Rectangle rec);
    Vector2 getMousePosition();
    bool isMouseButtonPressed(int button);
};

#endif