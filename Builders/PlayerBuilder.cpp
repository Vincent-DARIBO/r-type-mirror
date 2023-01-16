#ifndef PLAYERBUILDER_HPP_
#define PLAYERBUILDER_HPP_

#include "PlayerBuilder.hpp"

PlayerBuilder::PlayerBuilder(/* args */)
{
}

PlayerBuilder::~PlayerBuilder()
{
}

// void PlayerBuilder::setTexture() {
//     std::shared_ptr<Components::Object> texture(new Components::Object());

//     _components.push_back(texture);
// }

void PlayerBuilder::setObject()
{
    std::shared_ptr<Components::Object> object(new Components::Object());

    _components.push_back(object);
}

void PlayerBuilder::setPosition()
{
    std::shared_ptr<Components::Position> position(new Components::Position());

    _components.push_back(position);
}

void PlayerBuilder::setAnimation()
{
    std::shared_ptr<Components::Animation> animation(new Components::Animation());

    _components.push_back(animation);
}

void PlayerBuilder::setMovement()
{
    std::shared_ptr<Components::Movements> mvt(new Components::Movements());

    _components.push_back(mvt);
}

void PlayerBuilder::setCollision()
{
    // std::shared_ptr<Components::Collision> collision(new Components::Collision());
    std::shared_ptr<Components::Collision> collision = std::make_shared<Components::Collision>();
    _components.push_back(collision);
}

void PlayerBuilder::setIA(int id)
{
    // std::shared_ptr<Components::Ia> ia(new Components::Ia(id));

    // _components.push_back(ia);
}

void PlayerBuilder::addComps()
{
    _entity.addComponents(_components);
}

Entity &PlayerBuilder::getEntity()
{
    return _entity;
}

#endif