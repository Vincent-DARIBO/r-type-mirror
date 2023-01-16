#ifndef _PROJECTILES_BUILDER_
#define _PROJECTILES_BUILDER_

#include "./IEntityBuilder.hpp"
#include "../Components/Movements.hpp"
#include "../Components/Collision.hpp"
#include "../Components/Position.hpp"
#include "../Components/Animation.hpp"
#include <memory>

class ProjectilesBuilder
{
private:
    Entity _entity;
    std::vector<std::shared_ptr<Components::IComponent>> _components;
public:
    ProjectilesBuilder(/* args */);
    ~ProjectilesBuilder();
    void setObject();
    void setPosition();
    void setAnimation();
    void setMovement();
    void setCollision();
    void setIA(int id);
    void addComps();
    Entity &getEntity();
};

#endif