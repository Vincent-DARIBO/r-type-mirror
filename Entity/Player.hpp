#ifndef _PLAYER_
#define _PLAYER_

#include "./Entity.hpp"
#include "../Components/IComponent.hpp"
#include "../System/Keys.hpp"

class Player : public Entity
{
private:
    Keys _keys;
public:
    Player(/* args */);
    ~Player();
    void setKeys(Keys keys);
    Keys getKeys();
};

#endif