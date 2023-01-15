#include "Entity.hpp"

#include <iostream>

void Entity::addComponents(std::vector<std::shared_ptr<Components::IComponent>> components)
{
    for (auto i: components) {
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
    // std::cout << "getPositionComp" << std::endl;
    for (auto i : _components)
    {
        // std::cout << i->getComponentType() << std::endl; 
        if (i->getComponentType() == POSITION)
            return std::reinterpret_pointer_cast<Components::Position>(i);
    }
    throw "Object comp not in entity";
}