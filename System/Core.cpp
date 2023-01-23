#include "./Core.hpp"

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
    _gameState = MENU;
    menu();
}

void Core::menu()
{
    while (!windowShouldClose() && _gameState == MENU)
    {
        if (IsKeyDown(R_TYPE_KEY_E))
        {
            _gameState = GAME;
            game();
        }
        if (IsKeyDown(R_TYPE_KEY_R))
        {
            _gameState = OPTION;
            option();
        }
        getDraw().beginDrawing();
        getDraw().clearBackground(RAYWHITE);
        getDraw().drawText("menu\nappuyez sur e pour passer au jeu", {600, 300}, 20, RED);
        getDraw().drawText("appuyez sur r pour passer aux options", {600, 400}, 20, RED);
        getDraw().endDrawing();
    }
}

void Core::option()
{
    while (!windowShouldClose() && _gameState == OPTION)
    {
        if (IsKeyPressed(R_TYPE_KEY_O))
            setFps(getFps() - 1);
        if (IsKeyPressed(R_TYPE_KEY_P))
            setFps(getFps() + 1);
        getDraw().beginDrawing();
        getDraw().clearBackground(RAYWHITE);
        getDraw().drawText("appuyez sur o pour diminuer les fps", {600, 300}, 20, RED);
        getDraw().drawText("appuyez sur p pour augmenter les fps", {600, 400}, 20, RED);
        getDraw().drawText(std::to_string(getFps()), {200, 300}, 20, RED);
        getDraw().endDrawing();
    }
}

void Core::game()
{
    _playerFactory = std::make_unique<PlayerFactory>();
    _projectileFactory = std::make_unique<ProjectilesFactory>();
    _ennemyFactory = std::make_unique<EnnemyFactory>();
    _cameraFactory = std::make_unique<CameraFactory>();

    Player *player = reinterpret_cast<Player *>(_playerFactory->create());
    Ennemy *ennemy = reinterpret_cast<Ennemy *>(_ennemyFactory->create());
    rTypeCamera *camera = reinterpret_cast<rTypeCamera *>(_cameraFactory->create());

    Components::Position poscomp({350, 280});
    Components::Object objcomp("../sprites/r-typesheet23.gif");
    Components::Movements movcomp(5);
    Components::Animation animcomp(5, 8);

    player->addComp(std::make_shared<Components::Position>(poscomp));
    player->addComp(std::make_shared<Components::Object>(objcomp));
    player->addComp(std::make_shared<Components::Movements>(movcomp));
    player->addComp(std::make_shared<Components::Animation>(animcomp));

    player->getObjectComp()->setRefRect({0.0f, 0.0f, (float)player->getObjectComp()->getTexture().width / 8, (float)player->getObjectComp()->getTexture().height / 2});

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

    ennemy->getObjectComp()->setRefRect({0.0f, 0.0f, (float)ennemy->getObjectComp()->getTexture().width / 8, (float)ennemy->getObjectComp()->getTexture().height / 2});

    std::vector<Projectiles *> projectiles;

    int boxPositionY = getScreenSize().screenHeight / 2 - 40;
    int scrollSpeed = 4;

    getAudio().loadShotSound("../assets/Blaster.ogg");

    player->setKeys({R_TYPE_UP, R_TYPE_RIGHT, R_TYPE_DOWN, R_TYPE_LEFT});

    Components::CameraComp cameraComp((Vector2){getScreenSize().screenWidth / 2.0f, getScreenSize().screenHeight / 2.0f}, (Vector2){getScreenSize().screenWidth / 2.0f, getScreenSize().screenHeight / 2.0f}, 0.0f, 1.0f);
    camera->addComp(std::make_shared<Components::CameraComp>(cameraComp));
    
    while (!windowShouldClose() && _gameState == GAME)
    {

        player->getAnimationComp()->animate(getFps(), player->getObjectComp());
        ennemy->getAnimationComp()->animate(getFps(), ennemy->getObjectComp());
        // ennemy->getMovementsComp()->move(ennemy->getPositionComp(), LEFT);
        ennemy->getAiComp()->play(ennemy->getPositionComp(), ennemy->getMovementsComp());

        getInput().handler(player, projectiles, _projectileFactory, getScreenSize(), getAudio());

        for (std::size_t i = 0; i < projectiles.size(); i++)
        {
            projectiles.at(i)->getAnimationComp()->animate(getFps(), projectiles.at(i)->getObjectComp());
            projectiles.at(i)->getMovementsComp()->move(projectiles.at(i)->getPositionComp(), RIGHT);
        }

        deleteProjectiles(projectiles);

        boxPositionY -= (GetMouseWheelMove() * scrollSpeed);

        if (IsKeyDown(R_TYPE_KEY_W))
            camera->getCameraComp()->setRotation(-30);
        else if (IsKeyDown(R_TYPE_KEY_X))
            camera->getCameraComp()->setRotation(30);

        getDraw().beginDrawing();

        getDraw().clearBackground(RAYWHITE);

        beginMode2d(camera->getCameraComp()->getCamera2d());

        getDraw().drawTextureRec(player->getObjectComp()->getTexture(), player->getObjectComp()->getRect(), player->getPositionComp()->getPosition(), WHITE);
        for (std::size_t i = 0; i < projectiles.size(); i++)
            getDraw().drawTextureRec(projectiles.at(i)->getObjectComp()->getTexture(), projectiles.at(i)->getObjectComp()->getRect(), projectiles.at(i)->getPositionComp()->getPosition(), WHITE);

        getDraw().drawTextureRec(ennemy->getObjectComp()->getTexture(), ennemy->getObjectComp()->getRect(), ennemy->getPositionComp()->getPosition(), WHITE);
        getDraw().drawRectangleLines({15, 40}, player->getObjectComp()->getTexture().width, player->getObjectComp()->getTexture().height, LIME);
        getDraw().drawRectangleLines({15 + (int)player->getObjectComp()->getRect().x, 40 + (int)player->getObjectComp()->getRect().y}, (int)player->getObjectComp()->getRect().width, (int)player->getObjectComp()->getRect().height, RED);
        getDraw().drawTextureRec(player->getObjectComp()->getTexture(), player->getObjectComp()->getRect(), player->getPositionComp()->getPosition(), WHITE);
        getDraw().drawTexture(player->getObjectComp()->getTexture(), {15, 40}, WHITE);
        getDraw().drawRectangle({getScreenSize().screenWidth / 2 - 40, boxPositionY}, 80, 80, MAROON);

        endMode2d();
        getDraw().endDrawing();
    }

    for (std::size_t i = 0; i < projectiles.size(); i++)
        projectiles.at(i)->getObjectComp()->unloadTexture();

    unloadTexture(player->getObjectComp()->getTexture());

    getAudio().unloadShotSound();
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

void Core::beginMode2d(Camera2D &camera)
{
    BeginMode2D(camera);
}