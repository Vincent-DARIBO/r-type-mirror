#ifndef _PLAYER_
#define _PLAYER_

#include "./Entity.hpp"
#include "../Components/IComponent.hpp"

class Player : public Entity
{
private:

public:
    Player(/* args */);
    ~Player();
};

Player::Player(/* args */)
{
}

Player::~Player()
{
}

#endif