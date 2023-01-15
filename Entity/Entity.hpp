#ifndef _ENTITY_
#define _ENTITY_

#include "../Components/IComponent.hpp"
#include "../Components/Object.hpp"
#include "../Components/Text.hpp"
#include "../Components/Collision.hpp"
#include "../Components/Position.hpp"
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
        std::shared_ptr<Components::Text> getTextComp();
        std::shared_ptr<Components::Collision> getCollisionComp();
        // std::shared_ptr<Components::Ia>getIAComp();
        size_t getnbBox();
        void setNbBox(size_t);

    private:
        std::vector<std::shared_ptr<Components::IComponent>> _components;
};

#endif