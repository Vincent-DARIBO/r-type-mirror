#include "./EnnemyFactory.hpp"

EnnemyFactory::EnnemyFactory(/* args */)
{
}

EnnemyFactory::~EnnemyFactory()
{
}

Entity *EnnemyFactory::create() const 
{
    return new Ennemy();
}