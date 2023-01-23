#ifndef _HEALTH_
#define _HEALTH_

#include "./IComponent.hpp"

namespace Components
{
    class Health : public IComponent
    {
    private:
        int _hp;
        int _maxHp;

    public:
        Health(int maxHp);
        ~Health();
        int getHp();
        void setHp(int hp);
        void setMaxHp(int maxHp);
    };
}

#endif