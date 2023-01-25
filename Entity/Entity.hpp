#ifndef _ENTITY_
#define _ENTITY_

#include "../Components/Object.hpp"
#include "../Components/Text.hpp"
#include "../Components/Collision.hpp"
#include "../Components/Position.hpp"
#include "../Components/Movements.hpp"
#include "../Components/Animation.hpp"
#include "../Components/CameraComp.hpp"
#include "../Components/Ai.hpp"
#include "../Components/Health.hpp"
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
    std::shared_ptr<Components::CameraComp> getCameraComp();
    std::shared_ptr<Components::Ai> getAiComp();
    std::shared_ptr<Components::Health> getHealthComp();
    std::shared_ptr<Components::Collision> getCollisionComp();

private:
    std::vector<std::shared_ptr<Components::IComponent>> _components;
};

#endif