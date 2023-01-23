#include "./Ai.hpp"
#include <iostream>

Components::Ai::Ai(/* args */)
{
    _componentType = AI;
    _direction = LEFT;
}

Components::Ai::~Ai()
{
}

void Components::Ai::play(std::shared_ptr<Components::Position> pos, std::shared_ptr<Components::Movements> movement)
{
    if (pos->getPosition().x < 1000)
        _direction = RIGHT;
    else if (pos->getPosition().x > 1600) //mettre la taille de l'écran - genre 1/10 de la taille de l'écran
        _direction = LEFT;
    movement->move(pos, _direction);
}