#ifndef _PLAYER_BUILDER_
#define _PLAYER_BUILDER_

#include "./IEntityBuilder.hpp"
#include "../Components/Movements.hpp"
#include "../Components/Collision.hpp"
#include "../Components/Position.hpp"
#include "../Components/Animation.hpp"

class PlayerBuilder : public IEntityBuilder {
    public:
        PlayerBuilder();
        ~PlayerBuilder();
        // void reset(position_t position);
        // void setTexture();
        void setObject();
        void setPosition();
        void setAnimation();
        void setMovement();
        void setCollision();
        void setIA(int id);
        void addComps();
        Entity &getEntity();

    private:
        Entity _entity;
        std::vector<std::shared_ptr<Components::IComponent>> _components;
};

#endif