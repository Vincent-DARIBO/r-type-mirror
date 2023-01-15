#include "./Components/IComponent.hpp"
#include "./System/Core.hpp"
#include "./System/Draw.hpp"
#include "./Entity/Entity.hpp"
#include "./Builders/Director.hpp"
#include <iostream>

int main()
{
    Core core(1920, 1080, "r-type", 60);

    Director director;

    Entity player = director.make(EntityTypes::PLAYER);
    player.getObjectComp()->setTexture("../sprites/r-typesheet23.gif");
    player.getPositionComp()->setPosition({350.0f, 280.0f});

    int boxPositionY = core.getScreenHeight() / 2 - 40;
    int scrollSpeed = 4;

    player.getObjectComp()->setRect({0.0f, 0.0f, (float)player.getObjectComp()->getTexture().width / 8, (float)player.getObjectComp()->getTexture().height / 2});

    int currentFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 5;

    while (!core.windowShouldClose())
    {

        framesCounter++;

        if (framesCounter >= (60 / framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 7)
                currentFrame = 0;

            player.getObjectComp()->setRect({(float)currentFrame * (float)player.getObjectComp()->getTexture().width / 8, player.getObjectComp()->getRect().y, player.getObjectComp()->getRect().width, player.getObjectComp()->getRect().height});
        }

        boxPositionY -= (GetMouseWheelMove() * scrollSpeed);
        core.getDraw().beginDrawing();
        core.getDraw().clearBackground(RAYWHITE);

        core.getDraw().drawTexture(player.getObjectComp()->getTexture(), 15, 40, WHITE);
        // DrawRectangleLines(15, 40, player.getObjectComp()->getTexture().width, player.getObjectComp()->getTexture().height, LIME);
        // DrawRectangleLines(15 + (int)player.getObjectComp()->getRect().x, 40 + (int)player.getObjectComp()->getRect().y, (int)player.getObjectComp()->getRect().width, (int)player.getObjectComp()->getRect().height, RED);
        core.getDraw().drawTextureRec(player.getObjectComp()->getTexture(), player.getObjectComp()->getRect(), player.getPositionComp()->getPosition(), WHITE);

        core.getDraw().drawRectangle(core.getScreenWidth() / 2 - 40, boxPositionY, 80, 80, MAROON);
        core.getDraw().endDrawing();
    }
    core.unloadTexture(player.getObjectComp()->getTexture());

    core.closeWindow();
}