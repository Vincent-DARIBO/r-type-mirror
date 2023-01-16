#include "./Components/IComponent.hpp"
#include "./System/Core.hpp"
// #include "./System/Draw.hpp"
#include "./Entity/Entity.hpp"
#include "./Builders/Director.hpp"
#include <iostream>

#define MAX_FRAME_DELAY 20
#define MIN_FRAME_DELAY 1

int main()
{
    Core core(1700, 800, "r-type", 60);

    Director director;

    std::vector<Entity> projectiles;
    Entity projectile;
    std::shared_ptr<Components::Position> position;
    projectile.addComponent(position);
    projectiles.push_back(projectile);
    // projectiles.at(0).getPositionComp();//->setPosition({155,455});

    // std::cout << "x = "<< projectiles.at(0).getPositionComp()->getPosition().x << " y = " << projectiles.at(0).getPositionComp()->getPosition().y;

    Entity player = director.make(EntityTypes::PLAYER);
    // std::vector<Entity> projectiles;

    player.getObjectComp()->setTexture("../sprites/r-typesheet23.gif");
    player.getPositionComp()->setPosition({350.0f, 280.0f});
    player.getMovementsComp()->setSpeed(5);
    int boxPositionY = core.getScreenHeight() / 2 - 40;
    int scrollSpeed = 4;

    player.getObjectComp()->setRect({0.0f, 0.0f, (float)player.getObjectComp()->getTexture().width / 8, (float)player.getObjectComp()->getTexture().height / 2});

    player.getAnimationComp()->setFrames(0, 0, 5, 8);

    while (!core.windowShouldClose())
    {

        player.getAnimationComp()->animate(core.getFps(), *player.getObjectComp());

        if (IsKeyDown(KEY_UP))
            player.getMovementsComp()->move(*player.getPositionComp(), UP);
        if (IsKeyDown(KEY_RIGHT))
            player.getMovementsComp()->move(*player.getPositionComp(), RIGHT);
        if (IsKeyDown(KEY_DOWN))
            player.getMovementsComp()->move(*player.getPositionComp(), DOWN);
        if (IsKeyDown(KEY_LEFT))
            player.getMovementsComp()->move(*player.getPositionComp(), LEFT);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {

            // Entity proj = director.make(EntityTypes::PROJECTILES);
            // Entity tmp = proj;
            // tmp.getPositionComp()->setPosition({85, 98});
            // std::cout << "tmp pos = " << tmp.getPositionComp()->getPosition().x << "," << tmp.getPositionComp()->getPosition().y << std::endl;
            // projectiles.push_back(tmp);
            // std::cout << "proj0 pos = " << projectiles.at(0).getPositionComp()->getPosition().x << "," << projectiles.at(0).getPositionComp()->getPosition().y << std::endl;

            // projectiles.push_back(director.make(EntityTypes::PROJECTILES));
            // tmp.getPositionComp()->setPosition({100, 701});
            // std::cout << "proj0 pos = " << projectiles.at(0).getPositionComp()->getPosition().x << "," << projectiles.at(0).getPositionComp()->getPosition().y << std::endl;
            // std::cout << "proj1 pos = " << projectiles.at(1).getPositionComp()->getPosition().x << "," << projectiles.at(1).getPositionComp()->getPosition().y << std::endl;

            // Entity proj1 = director.make(EntityTypes::PROJECTILES);
            // Entity proj2 = director.make(EntityTypes::PROJECTILES);
            // proj1.getPositionComp()->setPosition({100, 100});
            // proj2.getPositionComp()->setPosition({600, 600});
            // std::cout << "proj1 x = " << proj1.getPositionComp()->getPosition().x << " y = " << proj1.getPositionComp()->getPosition().y << std::endl;
            // std::cout << "proj2 x = " << proj2.getPositionComp()->getPosition().x << " y = " << proj2.getPositionComp()->getPosition().x << std::endl;

            // projectiles.push_back(director.make(EntityTypes::PROJECTILES));
            // projectiles.at(projectfor (std::size_t i = 0; i < projectiles.size(); i++)
        // {
        //     // std::cout << "i = " << i << " pos = " << projectiles.at(i).getPositionComp()->getPosition().x << "," << projectiles.at(i).getPositionComp()->getPosition().y << std::endl;
        //     core.getDraw().drawTextureRec(projectiles.at(i).getObjectComp()->getTexture(), projectiles.at(i).getObjectComp()->getRect(), projectiles.at(i).getPositionComp()->getPosition(), WHITE);
        // }iles.size() - 1).getObjectComp()->setRect({232.0f, 103.0f, 16, 12});
            // projectiles.at(projectiles.size() - 1).getPositionComp()->setPosition(player.getPositionComp()->getPosition());
            // for (std::size_t i = 0; i < projectiles.size(); i++)
            // {
            //     std::cout << "len = " << projectiles.size() << std::endl;
            //     std::cout << "i = " << i << " pos = " << projectiles.at(i).getPositionComp()->getPosition().x << "," << projectiles.at(i).getPositionComp()->getPosition().y << std::endl;
            //     std::cout << "x = " << projectiles.at(projectiles.size() - 1).getObjectComp()->getRect().x << "y = " << projectiles.at(projectiles.size() - 1).getObjectComp()->getRect().y << "width = " << projectiles.at(projectiles.size() - 1).getObjectComp()->getRect().width << "height = " << projectiles.at(projectiles.size() - 1).getObjectComp()->getRect().height << std::endl;
            // }
        }

        boxPositionY -= (GetMouseWheelMove() * scrollSpeed);

        core.getDraw().beginDrawing();
        core.getDraw().clearBackground(RAYWHITE);

        core.getDraw().drawTexture(player.getObjectComp()->getTexture(), 15, 40, WHITE);

        // for (std::size_t i = 0; i < projectiles.size(); i++)
        // {
        //     // std::cout << "i = " << i << " pos = " << projectiles.at(i).getPositionComp()->getPosition().x << "," << projectiles.at(i).getPositionComp()->getPosition().y << std::endl;
        //     core.getDraw().drawTextureRec(projectiles.at(i).getObjectComp()->getTexture(), projectiles.at(i).getObjectComp()->getRect(), projectiles.at(i).getPositionComp()->getPosition(), WHITE);
        // }

        DrawRectangleLines(15, 40, player.getObjectComp()->getTexture().width, player.getObjectComp()->getTexture().height, LIME);
        DrawRectangleLines(15 + (int)player.getObjectComp()->getRect().x, 40 + (int)player.getObjectComp()->getRect().y, (int)player.getObjectComp()->getRect().width, (int)player.getObjectComp()->getRect().height, RED);
        core.getDraw().drawTextureRec(player.getObjectComp()->getTexture(), player.getObjectComp()->getRect(), player.getPositionComp()->getPosition(), WHITE);

        core.getDraw().drawRectangle(core.getScreenWidth() / 2 - 40, boxPositionY, 80, 80, MAROON);
        core.getDraw().endDrawing();
    }
    core.unloadTexture(player.getObjectComp()->getTexture());

    core.closeWindow();
}