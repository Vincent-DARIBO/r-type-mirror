#ifndef _AI_
#define _AI_

#include "./IComponent.hpp"
#include "./Position.hpp"
#include "./Movements.hpp"

namespace Components
{
    class Ai : public IComponent
    {
    private:
        Direction _direction;
    public:
        Ai(/* args */);
        ~Ai();
        void play(std::shared_ptr<Components::Position> pos, std::shared_ptr<Components::Movements> movement);
    };
}

#endif