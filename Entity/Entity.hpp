#ifndef _ENTITY_
#define _ENTITY_

#include "../Components/IComponent.hpp"
#include "../Components/Object.hpp"
#include "../Components/Text.hpp"
#include "../Components/Collision.hpp"
#include "../Components/Position.hpp"
#include "../Components/Movements.hpp"
#include "../Components/Animation.hpp"
#include <memory>
#include <vector>

class Entity
{
public:
    Entity() = default;
    ~Entity() = default;
    void addComp(std::shared_ptr<Components::IComponent> comp);
    std::shared_ptr<Components::Position> getPositionComp();
    std::shared_ptr<Components::Object> getObjectComp();
    std::shared_ptr<Components::Movements> getMovementsComp();
    std::shared_ptr<Components::Animation> getAnimationComp();

private:
    std::vector<std::shared_ptr<Components::IComponent>> _components;
};

void Entity::addComp(std::shared_ptr<Components::IComponent> comp)
{
    _components.push_back(comp);
}

std::shared_ptr<Components::Position> Entity::getPositionComp()
{
    for (auto i : _components)
        if (i->getComponentType() == POSITION)
            return std::reinterpret_pointer_cast<Components::Position>(i);
    throw "comp position not in entity";
}

std::shared_ptr<Components::Object> Entity::getObjectComp()
{
    for (auto i : _components)
        if (i->getComponentType() == OBJECT)
            return std::reinterpret_pointer_cast<Components::Object>(i);
    throw "comp position not in entity";
}

std::shared_ptr<Components::Movements> Entity::getMovementsComp()
{
    for (auto i : _components)
        if (i->getComponentType() == MOVEMENTS)
            return std::reinterpret_pointer_cast<Components::Movements>(i);
    throw "comp position not in entity";
}

std::shared_ptr<Components::Animation> Entity::getAnimationComp()
{
    for (auto i : _components)
        if (i->getComponentType() == ANIMATION)
            return std::reinterpret_pointer_cast<Components::Animation>(i);
    throw "comp position not in entity";
}

#endif