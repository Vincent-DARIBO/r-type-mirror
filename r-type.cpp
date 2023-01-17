#include "./Components/IComponent.hpp"
#include "./System/Core.hpp"
// #include "./System/Draw.hpp"
#include "./Entity/Entity.hpp"
// #include "./Builders/Director.hpp"
#include <iostream>
#include "./Factory/PlayerFactory.hpp"
#include "./Factory/ProjectilesFactory.hpp"

int main()
{
    Core core(1700, 800, "r-type", 60);

    Factory *playerFactory = new PlayerFactory();
    Factory *projectileFactory = new ProjectilesFactory();

    Player *player = reinterpret_cast<Player *>(playerFactory->create());

    Components::Position poscomp({350, 280});
    Components::Object objcomp("../sprites/r-typesheet23.gif");
    Components::Movements movcomp(5);
    Components::Animation animcomp(0, 0, 5, 8);

    player->addComp(std::make_shared<Components::Position>(poscomp));
    player->addComp(std::make_shared<Components::Object>(objcomp));
    player->addComp(std::make_shared<Components::Movements>(movcomp));
    player->addComp(std::make_shared<Components::Animation>(animcomp));

    player->getObjectComp()->setRect({0.0f, 0.0f, (float)player->getObjectComp()->getTexture().width / 8, (float)player->getObjectComp()->getTexture().height / 2});

    std::vector<Projectiles *> projectiles;

    int boxPositionY = core.getScreenHeight() / 2 - 40;
    int scrollSpeed = 4;

    while (!core.windowShouldClose())
    {

        player->getAnimationComp()->animate(core.getFps(), player->getObjectComp());

        if (IsKeyDown(KEY_UP))
            player->getMovementsComp()->move(player->getPositionComp(), UP);
        if (IsKeyDown(KEY_RIGHT))
            player->getMovementsComp()->move(player->getPositionComp(), RIGHT);
        if (IsKeyDown(KEY_DOWN))
            player->getMovementsComp()->move(player->getPositionComp(), DOWN);
        if (IsKeyDown(KEY_LEFT))
            player->getMovementsComp()->move(player->getPositionComp(), LEFT);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            projectiles.push_back(reinterpret_cast<Projectiles *>(projectileFactory->create()));
            Components::Position posCompProj({player->getPositionComp()->getPosition().x, player->getPositionComp()->getPosition().y});
            Components::Object objCompProj("../sprites/r-typesheet1.gif");
            projectiles.at(projectiles.size() - 1)->addComp(std::make_shared<Components::Position>(posCompProj));
            projectiles.at(projectiles.size() - 1)->addComp(std::make_shared<Components::Object>(objCompProj));
            projectiles.at(projectiles.size() - 1)->getObjectComp()->setRect({232.0f, 103.0f, 16, 12});
        }

        boxPositionY -= (GetMouseWheelMove() * scrollSpeed);
        core.getDraw().beginDrawing();

        core.getDraw().clearBackground(RAYWHITE);
        core.getDraw().drawTextureRec(player->getObjectComp()->getTexture(), player->getObjectComp()->getRect(), player->getPositionComp()->getPosition(), WHITE);
        for (std::size_t i = 0; i < projectiles.size(); i++)
            core.getDraw().drawTextureRec(projectiles.at(i)->getObjectComp()->getTexture(), projectiles.at(i)->getObjectComp()->getRect(), projectiles.at(i)->getPositionComp()->getPosition(), WHITE);

        DrawRectangleLines(15, 40, player->getObjectComp()->getTexture().width, player->getObjectComp()->getTexture().height, LIME);
        DrawRectangleLines(15 + (int)player->getObjectComp()->getRect().x, 40 + (int)player->getObjectComp()->getRect().y, (int)player->getObjectComp()->getRect().width, (int)player->getObjectComp()->getRect().height, RED);
        core.getDraw().drawTextureRec(player->getObjectComp()->getTexture(), player->getObjectComp()->getRect(), player->getPositionComp()->getPosition(), WHITE);
        core.getDraw().drawTexture(player->getObjectComp()->getTexture(), 15, 40, WHITE);
        core.getDraw().drawRectangle(core.getScreenWidth() / 2 - 40, boxPositionY, 80, 80, MAROON);

        core.getDraw().endDrawing();
    }
    core.unloadTexture(player->getObjectComp()->getTexture());

    core.closeWindow();
}