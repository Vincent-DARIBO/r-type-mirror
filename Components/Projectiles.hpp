#ifndef _PRJECTILES_
#define _PRJECTILES_

#include "./IComponent.hpp"

namespace Components
{
    class Projectiles : public IComponent
    {
    private:
        int _damage;
        bool _isFriendlyFire;
        vector2int _pos;

    public:
        Projectiles(/* args */);
        ~Projectiles();
    };
}

#endif