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

std::shared_ptr<Components::Health> Entity::getHealthComp()
{
    for (auto i : _components)
        if (i->getComponentType() == HEALTH)
            return std::reinterpret_pointer_cast<Components::Health>(i);
    throw "comp Health not in entity";
}

std::shared_ptr<Components::Collision> Entity::getCollisionComp()
{
    for (auto i : _components)
        if (i->getComponentType() == COLLISION)
            return std::reinterpret_pointer_cast<Components::Collision>(i);
    throw "comp Collision not in entity";
}

std::shared_ptr<Components::Text> Entity::getTextComp()
{
    for (auto i : _components)
        if (i->getComponentType() == TEXT)
            return std::reinterpret_pointer_cast<Components::Text>(i);
    throw "comp Text not in entity";
}