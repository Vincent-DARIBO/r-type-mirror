#include "./PlayerFactory.hpp"

PlayerFactory::PlayerFactory(/* args */)
{
}

PlayerFactory::~PlayerFactory()
{
}

Entity *PlayerFactory::create() const 
{
    Player *player = new Player();
    Components::Position poscomp({350, 280});
    Components::Object objcomp("../sprites/r-typesheet23.gif");
    Components::Movements movcomp(5);
    Components::Animation animcomp(5, 8);
    Components::Health healthComp(3);
    Components::Collision collisionComp;

    player->addComp(std::make_shared<Components::Position>(poscomp));
    player->addComp(std::make_shared<Components::Object>(objcomp));
    player->addComp(std::make_shared<Components::Movements>(movcomp));
    player->addComp(std::make_shared<Components::Animation>(animcomp));
    player->addComp(std::make_shared<Components::Health>(healthComp));
    player->addComp(std::make_shared<Components::Collision>(collisionComp));
    return player;
}