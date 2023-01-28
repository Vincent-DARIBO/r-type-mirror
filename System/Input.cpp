#include "./Input.hpp"
#include "../Factory/ProjectilesFactory.hpp"

Input::Input(/* args */)
{
}

Input::~Input()
{
}

bool Input::isKeyPressed(int key)
{
    return IsKeyPressed(key);
}

bool Input::isKeyDown(int key)
{
    return IsKeyDown(key);
}

bool Input::checkCollisionPointRec(Vector2 point, Rectangle rec)
{
    return CheckCollisionPointRec(point, rec);
}

Vector2 Input::getMousePosition()
{
    return GetMousePosition();   
}

bool Input::isMouseButtonPressed(int button)
{
    return IsMouseButtonPressed(button);
}

void Input::handler(Player *player, std::vector<Projectiles *> &projectiles, std::unique_ptr<Factory> &projectileFactory, ScreenSize screenSize, Audio &audio)
{    
    if (isKeyDown(player->getKeys().key_up) && player->getPositionComp()->getPosition().y - player->getMovementsComp()->getSpeed() >= 0)
        player->getMovementsComp()->move(player->getPositionComp(), UP);
    if (isKeyDown(player->getKeys().key_right) && player->getPositionComp()->getPosition().x + player->getMovementsComp()->getSpeed() <= screenSize.screenWidth - player->getObjectComp()->getRect().width)
        player->getMovementsComp()->move(player->getPositionComp(), RIGHT);
    if (isKeyDown(player->getKeys().key_down) && player->getPositionComp()->getPosition().y + player->getMovementsComp()->getSpeed() + player->getObjectComp()->getRect().height < screenSize.screenHeight)
        player->getMovementsComp()->move(player->getPositionComp(), DOWN);
    if (isKeyDown(player->getKeys().key_left) && player->getPositionComp()->getPosition().x - player->getMovementsComp()->getSpeed() >= 0)
        player->getMovementsComp()->move(player->getPositionComp(), LEFT);
    if (isMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        audio.playShotSound();
        projectiles.push_back(reinterpret_cast<Projectiles *>(projectileFactory->create()));
        Components::Position posCompProj({player->getPositionComp()->getPosition().x, player->getPositionComp()->getPosition().y});
        Components::Object objCompProj("../sprites/GamePlay/explosion/r-typesheet1.gif");
        Components::Animation animCompProjectile(5, 2);
        Components::Movements moveCompProjectile(7);
        projectiles.at(projectiles.size() - 1)->addComp(std::make_shared<Components::Position>(posCompProj));
        projectiles.at(projectiles.size() - 1)->addComp(std::make_shared<Components::Object>(objCompProj));
        projectiles.at(projectiles.size() - 1)->addComp(std::make_shared<Components::Animation>(animCompProjectile));
        projectiles.at(projectiles.size() - 1)->addComp(std::make_shared<Components::Movements>(moveCompProjectile));
        projectiles.at(projectiles.size() - 1)->getObjectComp()->setRefRect({232.0f, 103.0f, 17, 12});
    }
}

bool Input::isInRect(Rectangle rect)
{
    if (checkCollisionPointRec(getMousePosition(), rect))
        return true;
    else
        return false;
}

bool Input::isClicked(Rectangle rect)
{
    if (checkCollisionPointRec(getMousePosition(), rect) && isMouseButtonPressed(R_TYPE_MOUSE_LEFT))
        return true;
    else
        return false;
}