#include "./Health.hpp"

Components::Health::Health(int maxHp)
{
    _componentType = HEALTH;
    _maxHp = maxHp;
    _hp = _maxHp;
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

void Components::Health::setMaxHp(int maxHp)
{
    _maxHp -= maxHp;
}