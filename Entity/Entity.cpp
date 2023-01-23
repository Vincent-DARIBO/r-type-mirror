#include "./Entity.hpp"

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
    throw "comp Object not in entity";
}

std::shared_ptr<Components::Movements> Entity::getMovementsComp()
{
    for (auto i : _components)
        if (i->getComponentType() == MOVEMENTS)
            return std::reinterpret_pointer_cast<Components::Movements>(i);
    throw "comp movement not in entity";
}

std::shared_ptr<Components::Animation> Entity::getAnimationComp()
{
    for (auto i : _components)
        if (i->getComponentType() == ANIMATION)
            return std::reinterpret_pointer_cast<Components::Animation>(i);
    throw "comp Animation not in entity";
}

std::shared_ptr<Components::CameraComp> Entity::getCameraComp()
{
    for (auto i : _components)
        if (i->getComponentType() == CAMERACOMP)
            return std::reinterpret_pointer_cast<Components::CameraComp>(i);
    throw "comp Camera not in entity";
}

std::shared_ptr<Components::Ai> Entity::getAiComp()
{
    for (auto i : _components)
        if (i->getComponentType() == AI)
            return std::reinterpret_pointer_cast<Components::Ai>(i);
    throw "comp Ai not in entity";
}