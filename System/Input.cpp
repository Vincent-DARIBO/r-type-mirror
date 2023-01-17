#include "./Input.hpp"
#include "../Factory/ProjectilesFactory.hpp"

Input::Input(/* args */)
{
}

Input::~Input()
{
}

void Input::handler(Player *player, std::vector<Projectiles *> *projectiles, std::unique_ptr<Factory> &projectileFactory)
{
    if (IsKeyDown(player->getKeys().key_up))
        player->getMovementsComp()->move(player->getPositionComp(), UP);
    if (IsKeyDown(player->getKeys().key_right))
        player->getMovementsComp()->move(player->getPositionComp(), RIGHT);
    if (IsKeyDown(player->getKeys().key_down))
        player->getMovementsComp()->move(player->getPositionComp(), DOWN);
    if (IsKeyDown(player->getKeys().key_left))
        player->getMovementsComp()->move(player->getPositionComp(), LEFT);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        // projectiles->push_back(reinterpret_cast<Projectiles *>(projectileFactory.create()));
        projectiles->push_back(reinterpret_cast<Projectiles *>(projectileFactory->create()));
        Components::Position posCompProj({player->getPositionComp()->getPosition().x, player->getPositionComp()->getPosition().y});
        Components::Object objCompProj("../sprites/r-typesheet1.gif");
        projectiles->at(projectiles->size() - 1)->addComp(std::make_shared<Components::Position>(posCompProj));
        projectiles->at(projectiles->size() - 1)->addComp(std::make_shared<Components::Object>(objCompProj));
        projectiles->at(projectiles->size() - 1)->getObjectComp()->setRect({232.0f, 103.0f, 16, 12});
    }
}