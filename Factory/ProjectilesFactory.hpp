#ifndef _PROJECTILES_FACTORY_
#define _PROJECTILES_FACTORY_

#include "./Factory.hpp"
#include "../Entity/Projectiles.hpp"

class ProjectilesFactory : public Factory
{
private:
    /* data */
public:
    ProjectilesFactory(/* args */);
    ~ProjectilesFactory();
    Entity *create() const override;
};

#endif