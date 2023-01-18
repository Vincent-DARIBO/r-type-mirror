#include "./ProjectilesFactory.hpp"

ProjectilesFactory::ProjectilesFactory(/* args */)
{
}

ProjectilesFactory::~ProjectilesFactory()
{
}

Entity *ProjectilesFactory::create() const
{
    return new Projectiles();
}