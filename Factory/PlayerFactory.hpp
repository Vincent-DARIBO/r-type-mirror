#ifndef _PLAYER_FACTORY_
#define _PLAYER_FACTORY_

#include "./Factory.hpp"
#include "../Entity/Player.hpp"

class PlayerFactory : public Factory
{
private:
    /* data */
public:
    PlayerFactory(/* args */);
    ~PlayerFactory();
    Entity *create() const override;
};

#endif