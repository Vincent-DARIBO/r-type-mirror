#include "./PlayerFactory.hpp"

PlayerFactory::PlayerFactory(/* args */)
{
}

PlayerFactory::~PlayerFactory()
{
}

Entity *PlayerFactory::create() const 
{
    return new Player();
}