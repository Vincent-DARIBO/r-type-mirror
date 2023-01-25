#include "./EnnemyFactory.hpp"

EnnemyFactory::EnnemyFactory(/* args */)
{
}

EnnemyFactory::~EnnemyFactory()
{
}

Entity *EnnemyFactory::create() const 
{
    Ennemy *ennemy = new Ennemy();
    Components::Position poscompEnnemy({1400, 400});
    Components::Object objcompEnnemy("../sprites/r-typesheet8.gif");
    Components::Movements movcompEnnemy(5);
    Components::Animation animcompEnnemy(5, 8);
    Components::Ai AiEnnemyComp;

    ennemy->addComp(std::make_shared<Components::Position>(poscompEnnemy));
    ennemy->addComp(std::make_shared<Components::Object>(objcompEnnemy));
    ennemy->addComp(std::make_shared<Components::Movements>(movcompEnnemy));
    ennemy->addComp(std::make_shared<Components::Animation>(animcompEnnemy));
    ennemy->addComp(std::make_shared<Components::Ai>(AiEnnemyComp));
    return ennemy;
}