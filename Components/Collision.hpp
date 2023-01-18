#ifndef _COLLISION_
#define _COLLISION_

#include "./IComponent.hpp"

namespace Components
{
    class Collision : public IComponent
    {
    private:
        /* data */
    public:
        Collision(/* args */);
        ~Collision();
    };
}
#endif