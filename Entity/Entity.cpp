#include "Entity.hpp"

#include <iostream>

void Entity::addComponents(std::vector<std::shared_ptr<Components::IComponent>> components)
{
    for (auto i : components)
    {
        _components.push_back(i);
    }
}

std::shared_ptr<Components::Object> Entity::getObjectComp()
{
    for (auto i : _components)
    {
        if (i->getComponentType() == OBJECT)
            return std::reinterpret_pointer_cast<Components::Object>(i);
    }
    throw "Object comp not in entity";
}

std::shared_ptr<Components::Position> Entity::getPositionComp()
{
    for (auto i : _components)
    {
        if (i->getComponentType() == POSITION)
            return std::reinterpret_pointer_cast<Components::Position>(i);
    }
    throw "Object comp not in entity";
}

std::shared_ptr<Components::Movements> Entity::getMovementsComp()
{
    for (auto i : _components)
    {
        if (i->getComponentType() == MOVEMENTS)
            return std::reinterpret_pointer_cast<Components::Movements>(i);
    }
    throw "Object comp not in entity";
}

std::shared_ptr<Components::Animation> Entity::getAnimationComp()
{
    for (auto i : _components)
    {
        if (i->getComponentType() == ANIMATION)
            return std::reinterpret_pointer_cast<Components::Animation>(i);
    }
    throw "Object comp not in entity";
}

Entity Entity::operator=(Entity &entity)
{
    _components = entity._components;
    return *this;
}

void Entity::addComponent(std::shared_ptr<Components::Position> comp)
{
    std::cout << "okk" << std::endl;
    _components.push_back(comp);
    std::cout << "-----" << std::endl;
}