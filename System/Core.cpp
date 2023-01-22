#include "./Core.hpp"
#include "../Factory/PlayerFactory.hpp"
#include "../Factory/ProjectilesFactory.hpp"

Core::~Core()
{
    closeAudioDevice();
    closeWindow();

}

Core::Core(ScreenSize screenSize, std::string name, int fps)
{
    _screenSize = screenSize;
    InitWindow(_screenSize.screenWidth, _screenSize.screenHeight, name.c_str());
    _fps = fps;
    SetTargetFPS(_fps);
    initAudioDevice();
    menu();
}

void Core::menu()
{
    _gameState = MENU;
    while (!windowShouldClose() && _gameState == MENU) {
        if (IsKeyDown(KEY_E))
            _gameState = GAME;
        getDraw().beginDrawing();
        getDraw().clearBackground(RAYWHITE);
        getDraw().endDrawing();
    }
    game();
}

void Core::game()
{
    std::unique_ptr<Factory> playerFactory = std::make_unique<PlayerFactory>();
    std::unique_ptr<Factory> projectileFactory = std::make_unique<ProjectilesFactory>();

    Player *player = reinterpret_cast<Player *>(playerFactory->create());

    Components::Position poscomp({350, 280});
    Components::Object objcomp("../sprites/r-typesheet23.gif");
    Components::Movements movcomp(5);
    Components::Animation animcomp(5, 8);

    player->addComp(std::make_shared<Components::Position>(poscomp));
    player->addComp(std::make_shared<Components::Object>(objcomp));
    player->addComp(std::make_shared<Components::Movements>(movcomp));
    player->addComp(std::make_shared<Components::Animation>(animcomp));

    player->getObjectComp()->setRefRect({0.0f, 0.0f, (float)player->getObjectComp()->getTexture().width / 8, (float)player->getObjectComp()->getTexture().height / 2});

    std::vector<Projectiles *> projectiles;

    int boxPositionY = getScreenSize().screenHeight / 2 - 40;
    int scrollSpeed = 4;

    getAudio().loadShotSound("../assets/Blaster.ogg");

    player->setKeys({KEY_UP, KEY_RIGHT, KEY_DOWN, KEY_LEFT});

    Camera2D camera = {0};
    camera.target = (Vector2){getScreenSize().screenWidth / 2.0f, getScreenSize().screenHeight / 2.0f};
    camera.offset = (Vector2){getScreenSize().screenWidth / 2.0f, getScreenSize().screenHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!windowShouldClose() && _gameState == GAME)
    {

        player->getAnimationComp()->animate(getFps(), player->getObjectComp());

        getInput().handler(player, projectiles, projectileFactory, getScreenSize(), getAudio());

        for (std::size_t i = 0; i < projectiles.size(); i++)
        {
            projectiles.at(i)->getAnimationComp()->animate(getFps(), projectiles.at(i)->getObjectComp());
            projectiles.at(i)->getMovementsComp()->move(projectiles.at(i)->getPositionComp(), RIGHT);
        }

        deleteProjectiles(projectiles);

        boxPositionY -= (GetMouseWheelMove() * scrollSpeed);

        if (IsKeyDown(KEY_Z)) // touche W sur un clavier AZERTY , raylib est en QWERTY
            camera.rotation = -30;
        else if (IsKeyDown(KEY_X))
            camera.rotation = 30;

        getDraw().beginDrawing();

        getDraw().clearBackground(RAYWHITE);

        beginMode2d(camera);

        getDraw().drawTextureRec(player->getObjectComp()->getTexture(), player->getObjectComp()->getRect(), player->getPositionComp()->getPosition(), WHITE);
        for (std::size_t i = 0; i < projectiles.size(); i++)
            getDraw().drawTextureRec(projectiles.at(i)->getObjectComp()->getTexture(), projectiles.at(i)->getObjectComp()->getRect(), projectiles.at(i)->getPositionComp()->getPosition(), WHITE);

        getDraw().drawRectangleLines(15, 40, player->getObjectComp()->getTexture().width, player->getObjectComp()->getTexture().height, LIME);
        getDraw().drawRectangleLines(15 + (int)player->getObjectComp()->getRect().x, 40 + (int)player->getObjectComp()->getRect().y, (int)player->getObjectComp()->getRect().width, (int)player->getObjectComp()->getRect().height, RED);
        getDraw().drawTextureRec(player->getObjectComp()->getTexture(), player->getObjectComp()->getRect(), player->getPositionComp()->getPosition(), WHITE);
        getDraw().drawTexture(player->getObjectComp()->getTexture(), 15, 40, WHITE);
        getDraw().drawRectangle(getScreenSize().screenWidth / 2 - 40, boxPositionY, 80, 80, MAROON);

        endMode2d();
        getDraw().endDrawing();
    }

    for (std::size_t i = 0; i < projectiles.size(); i++)
        projectiles.at(i)->getObjectComp()->unloadTexture();

    unloadTexture(player->getObjectComp()->getTexture());

    // getAudio().unloadShotSound();
}

void Core::setFps(int fps)
{
    _fps = fps;
    SetTargetFPS(_fps);
};

int Core::getFps()
{
    return _fps;
};

ScreenSize Core::getScreenSize()
{
    return _screenSize;
}

Draw Core::getDraw()
{
    return _draw;
}

Input Core::getInput()
{
    return _input;
}

bool Core::windowShouldClose()
{
    return WindowShouldClose();
}

void Core::closeWindow()
{
    CloseWindow();
}

void Core::unloadTexture(Texture2D texture)
{
    UnloadTexture(texture);
}

void Core::setInputs(int keyUp, int keyRight, int keyDown, int keyLeft)
{
    _keyUp = keyUp;
    std::cout << "_keyUp" << _keyUp << std::endl;
    _keyRight = keyRight;
    _keyDown = keyDown;
    _keyLeft = keyLeft;
}

Vector4 Core::getInputs()
{
    return {(float)_keyUp, (float)_keyRight, (float)_keyDown, (float)_keyLeft};
}

void Core::deleteProjectiles(std::vector<Projectiles *> &projectiles)
{
    for (std::size_t i = 0; i < projectiles.size(); i++)
    {
        if (projectiles.at(i)->getPositionComp()->getPosition().x >= _screenSize.screenWidth || projectiles.at(i)->getPositionComp()->getPosition().y >= _screenSize.screenHeight)
        {
            projectiles.at(i)->getObjectComp()->unloadTexture();
            projectiles.erase(projectiles.begin() + i);
        }
    }
}

Audio &Core::getAudio()
{
    return _audio;
}

void Core::closeAudioDevice()
{
    CloseAudioDevice();
}

void Core::endMode2d()
{
    EndMode2D();
}

void Core::initAudioDevice()
{
    InitAudioDevice();
}

void Core::beginMode2d(Camera2D camera)
{
    BeginMode2D(camera);
}