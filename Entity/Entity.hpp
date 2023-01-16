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

class Entity {
    public:
        Entity() = default;
        ~Entity() = default;
        void addComponents(std::vector<std::shared_ptr<Components::IComponent>> components);
        // std::shared_ptr<Components::Camera>getCameraComp() const;
        std::shared_ptr<Components::Object> getObjectComp();
        std::shared_ptr<Components::Position> getPositionComp();
        std::shared_ptr<Components::Movements> getMovementsComp();
        std::shared_ptr<Components::Text> getTextComp();
        std::shared_ptr<Components::Collision> getCollisionComp();
        std::shared_ptr<Components::Animation> getAnimationComp();
        Entity operator= (Entity& entity);
        // std::shared_ptr<Components::Ia>getIAComp();
        void addComponent(std::shared_ptr<Components::Position> comp);
    private:
        std::vector<std::shared_ptr<Components::IComponent>> _components;
};

#endif