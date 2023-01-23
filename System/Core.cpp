#include "./Core.hpp"

Core::~Core()
{
    closeAudioDevice();
    closeWindow();
}

Core::Core(ScreenSize screenSize, std::string name, int fps)
{
    _screenSize = screenSize;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(_screenSize.screenWidth, _screenSize.screenHeight, name.c_str());
    _fps = fps;
    SetTargetFPS(_fps);
    initAudioDevice();
    if (!IsWindowFullscreen())
    {
        int monitor = GetCurrentMonitor();
        SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
        ToggleFullscreen();
    }
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

void Core::initGame()
{
    getAudio().loadShotSound("../assets/Blaster.ogg");
    _playerFactory = std::make_unique<PlayerFactory>();
    _projectileFactory = std::make_unique<ProjectilesFactory>();
    _ennemyFactory = std::make_unique<EnnemyFactory>();
    _cameraFactory = std::make_unique<CameraFactory>();
    _heartFactory = std::make_unique<HeartFactory>();

    _player = reinterpret_cast<Player *>(_playerFactory->create());
    _ennemy = reinterpret_cast<Ennemy *>(_ennemyFactory->create());
    _camera = reinterpret_cast<rTypeCamera *>(_cameraFactory->create());
    _heart = reinterpret_cast<Heart *>(_heartFactory->create());

    _player->getObjectComp()->setRefRect({0.0f, 0.0f, (float)_player->getObjectComp()->getTexture().width / 8, (float)_player->getObjectComp()->getTexture().height / 2});
    _ennemy->getObjectComp()->setRefRect({0.0f, 0.0f, (float)_ennemy->getObjectComp()->getTexture().width / 8, (float)_ennemy->getObjectComp()->getTexture().height / 2});
    _player->setKeys({R_TYPE_UP, R_TYPE_RIGHT, R_TYPE_DOWN, R_TYPE_LEFT});

}

void Core::drawGame()
{
    getDraw().beginDrawing();

    getDraw().clearBackground(RAYWHITE);

    beginMode2d(_camera->getCameraComp()->getCamera2d());

    for (int i = 0; i < _player->getHealthComp()->getHp(); i++)
        getDraw().drawTexture(_heart->getObjectComp()->getTexture(), {100 + 100 * i, 800}, WHITE);

    getDraw().drawTextureRec(_player->getObjectComp()->getTexture(), _player->getObjectComp()->getRect(), _player->getPositionComp()->getPosition(), WHITE);
    for (std::size_t i = 0; i < _projectiles.size(); i++)
        getDraw().drawTextureRec(_projectiles.at(i)->getObjectComp()->getTexture(), _projectiles.at(i)->getObjectComp()->getRect(), _projectiles.at(i)->getPositionComp()->getPosition(), WHITE);

    getDraw().drawTextureRec(_ennemy->getObjectComp()->getTexture(), _ennemy->getObjectComp()->getRect(), _ennemy->getPositionComp()->getPosition(), WHITE);
    getDraw().drawRectangleLines({15, 40}, _player->getObjectComp()->getTexture().width, _player->getObjectComp()->getTexture().height, LIME);
    getDraw().drawRectangleLines({15 + (int)_player->getObjectComp()->getRect().x, 40 + (int)_player->getObjectComp()->getRect().y}, (int)_player->getObjectComp()->getRect().width, (int)_player->getObjectComp()->getRect().height, RED);
    getDraw().drawTextureRec(_player->getObjectComp()->getTexture(), _player->getObjectComp()->getRect(), _player->getPositionComp()->getPosition(), WHITE);
    getDraw().drawTexture(_player->getObjectComp()->getTexture(), {15, 40}, WHITE);
    endMode2d();
    getDraw().endDrawing();
}

void Core::game()
{
    initGame();
    while (!windowShouldClose() && _gameState == GAME)
    {

        _player->getAnimationComp()->animate(getFps(), _player->getObjectComp());
        _ennemy->getAnimationComp()->animate(getFps(), _ennemy->getObjectComp());
        _ennemy->getAiComp()->play(_ennemy->getPositionComp(), _ennemy->getMovementsComp());

        getInput().handler(_player, _projectiles, _projectileFactory, getScreenSize(), getAudio());

        for (std::size_t i = 0; i < _projectiles.size(); i++)
        {
            _projectiles.at(i)->getAnimationComp()->animate(getFps(), _projectiles.at(i)->getObjectComp());
            _projectiles.at(i)->getMovementsComp()->move(_projectiles.at(i)->getPositionComp(), RIGHT);
        }

        deleteProjectiles(_projectiles);

        if (IsKeyDown(R_TYPE_KEY_W))
            _camera->getCameraComp()->setRotation(-30);
        else if (IsKeyDown(R_TYPE_KEY_X))
            _camera->getCameraComp()->setRotation(30);

        drawGame();
    }

    for (std::size_t i = 0; i < _projectiles.size(); i++)
        _projectiles.at(i)->getObjectComp()->unloadTexture();

    unloadTexture(_ennemy->getObjectComp()->getTexture());
    unloadTexture(_heart->getObjectComp()->getTexture());
    unloadTexture(_player->getObjectComp()->getTexture());

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