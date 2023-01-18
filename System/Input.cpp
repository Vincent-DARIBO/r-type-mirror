#include "./Input.hpp"
#include "../Factory/ProjectilesFactory.hpp"
#include "./Audio.hpp"

Input::Input(/* args */)
{
}

Input::~Input()
{
}

void Input::handler(Player *player, std::vector<Projectiles *> &projectiles, std::unique_ptr<Factory> &projectileFactory, ScreenSize screenSize, Audio audio)
{
    if (IsKeyDown(player->getKeys().key_up) && player->getPositionComp()->getPosition().y - player->getMovementsComp()->getSpeed() >= 0)
        player->getMovementsComp()->move(player->getPositionComp(), UP);
    if (IsKeyDown(player->getKeys().key_right) && player->getPositionComp()->getPosition().x + player->getMovementsComp()->getSpeed() <= screenSize.screenWidth - player->getObjectComp()->getRect().width)
        player->getMovementsComp()->move(player->getPositionComp(), RIGHT);
    if (IsKeyDown(player->getKeys().key_down) && player->getPositionComp()->getPosition().y + player->getMovementsComp()->getSpeed() <= screenSize.screenHeight - player->getObjectComp()->getRect().height)
        player->getMovementsComp()->move(player->getPositionComp(), DOWN);
    if (IsKeyDown(player->getKeys().key_left) && player->getPositionComp()->getPosition().x - player->getMovementsComp()->getSpeed() >= 0)
        player->getMovementsComp()->move(player->getPositionComp(), LEFT);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        // audio.playShotSound();
        projectiles.push_back(reinterpret_cast<Projectiles *>(projectileFactory->create()));
        Components::Position posCompProj({player->getPositionComp()->getPosition().x, player->getPositionComp()->getPosition().y});
        Components::Object objCompProj("../sprites/r-typesheet1.gif");
        Components::Animation animCompProjectile(0, 0, 5, 2);
        Components::Movements moveCompProjectile(7);
        projectiles.at(projectiles.size() - 1)->addComp(std::make_shared<Components::Position>(posCompProj));
        projectiles.at(projectiles.size() - 1)->addComp(std::make_shared<Components::Object>(objCompProj));
        projectiles.at(projectiles.size() - 1)->addComp(std::make_shared<Components::Animation>(animCompProjectile));
        projectiles.at(projectiles.size() - 1)->addComp(std::make_shared<Components::Movements>(moveCompProjectile));
        projectiles.at(projectiles.size() - 1)->getObjectComp()->setRefRect({232.0f, 103.0f, 17, 12});
    }
}