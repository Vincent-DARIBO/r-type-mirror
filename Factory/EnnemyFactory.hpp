#ifndef _ENNEMY_FACTORY_
#define _ENNEMY_FACTORY_

#include "./Factory.hpp"
#include "../Entity/Ennemy.hpp"

class EnnemyFactory : public Factory
{
private:
    /* data */
public:
    EnnemyFactory(/* args */);
    ~EnnemyFactory();
    Entity *create() const override;
};

#endif