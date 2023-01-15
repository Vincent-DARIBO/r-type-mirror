#include "./Health.hpp"

Components::Health::Health(/* args */)
{
}

Components::Health::~Health()
{
}

int Components::Health::getHp()
{
    return _hp;
}
void Components::Health::setHp(int hp)
{
    _hp -= hp;
}