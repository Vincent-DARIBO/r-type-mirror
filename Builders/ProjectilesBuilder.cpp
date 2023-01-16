#include "./ProjectilesBuilder.hpp"

ProjectilesBuilder::ProjectilesBuilder(/* args */)
{
}

ProjectilesBuilder::~ProjectilesBuilder()
{
}

void ProjectilesBuilder::setObject() {
    std::shared_ptr<Components::Object> object(new Components::Object());

    _components.push_back(object);
}

void ProjectilesBuilder::setPosition() {
    std::shared_ptr<Components::Position> position(new Components::Position());

    _components.push_back(position);
}

void ProjectilesBuilder::setMovement() {
    std::shared_ptr<Components::Movements> mvt(new Components::Movements());

    _components.push_back(mvt);
}

void ProjectilesBuilder::addComps() {
    _entity.addComponents(_components);
}

Entity &ProjectilesBuilder::getEntity() {
    return _entity;
}