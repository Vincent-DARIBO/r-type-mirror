#include "./Core.hpp"

Core::~Core()
{
    closeAudioDevice();
    closeWindow();
}

Core::Core(ScreenSize screenSize, std::string name, int fps)
{
    _screenSize = screenSize;
    setConfigFlags(FLAG_WINDOW_RESIZABLE);
    initWindow(name);
    setFps(fps);
    initAudioDevice();
    int monitor = getCurrentMonitor();
    if (!isWindowFullscreen())
    {
        setWindowSize(getMonitorWidth(monitor), getMonitorHeight(monitor));
        toggleFullscreen();
    }
    if (getMonitorWidth(monitor) > 1920 && getMonitorHeight(monitor) > 1080)
    {
        SetWindowSize(1920, 1080);
        toggleFullscreen();
    }

    _playerFactory = std::make_unique<PlayerFactory>();
    _projectileFactory = std::make_unique<ProjectilesFactory>();
    _ennemyFactory = std::make_unique<EnnemyFactory>();
    _cameraFactory = std::make_unique<CameraFactory>();
    _heartFactory = std::make_unique<HeartFactory>();
    _buttonFactory = std::make_unique<ButtonFactory>();
    _backgroundFactory = std::make_unique<BackgroundFactory>();
    _player = reinterpret_cast<Player *>(_playerFactory->create());
    _gameState = MENU;
    handleState();
}

void Core::handleState()
{
    while (1)
    {
        if (_gameState == MENU)
            menu();
        if (_gameState == GAME)
            game();
        if (_gameState == OPTION)
            option();
        if (_gameState == SPACESHIP_CHOISE)
            spaceShipChoise();
        if (_gameState == CLOSE)
            break;
    }
}

void Core::menu()
{
    //InitAudioDevice();
    _welcomeMenu = LoadTexture(GAME_MENU);
    _gameScreen = LoadTexture(GAME_SCREEN);
    //_music_menu = LoadMusicStream(MENU_MUSIC);
    while (!windowShouldClose() && _gameState == MENU)
    {
        if (_input.isKeyDown(R_TYPE_KEY_E))
            _gameState = GAME;
        if (_input.isKeyDown(R_TYPE_KEY_R))
            _gameState = OPTION;
        if (_input.isKeyDown(R_TYPE_KEY_T))
            _gameState = SPACESHIP_CHOISE;
        windowShouldClose();
        _draw.beginDrawing();
        _draw.clearBackground(RAYWHITE);
        _draw.drawTexture(_welcomeMenu, {0, 0}, WHITE);
        //SetMusicVolume(_music_menu, 0.5f);
        //PlayMusicStream(_music_menu);
        _draw.drawText("menu\nappuyez sur e pour passer au jeu", {600, 300}, 20, WHITE);
        _draw.drawText("appuyez sur r pour passer aux options", {600, 400}, 20, WHITE);
        _draw.drawText("appuyez sur t pour choisir votre vaisseau", {600, 500}, 20, WHITE);
        _draw.endDrawing();
    }
}

void Core::initSpaceShipChoise()
{
    _btnNext = reinterpret_cast<Button *>(_buttonFactory->create());
    _btnNext->getPositionComp()->setPosition({1525, 900});
    _btnNext->getTextComp()->setText("Next");
    _btnNext->getTextComp()->setRect({1525, 900, 100, 50});

    _btnReturn = reinterpret_cast<Button *>(_buttonFactory->create());
    _btnReturn->getPositionComp()->setPosition({70, 940});
    _btnReturn->getTextComp()->setText("Return");
    _btnReturn->getTextComp()->setRect({70, 940, 100, 50});

    _btnCreate = reinterpret_cast<Button *>(_buttonFactory->create());
    _btnCreate->getPositionComp()->setPosition({1535, 200});
    _btnCreate->getTextComp()->setText("Create");
    _btnCreate->getTextComp()->setRect({1535, 200, 100, 50});

    _btnJoin = reinterpret_cast<Button *>(_buttonFactory->create());
    _btnJoin->getPositionComp()->setPosition({1535, 300});
    _btnJoin->getTextComp()->setText("Join");
    _btnJoin->getTextComp()->setRect({1535, 300, 100, 50});

    _backgroundMenu = reinterpret_cast<Background *>(_backgroundFactory->create());
    _backgroundMenu->getObjectComp()->setTexture("../sprites/Menus/GameLobbyWithoutAnything.png");
    _player->getPositionComp()->setPosition({130, 650});
}

void Core::inputSpaceShipChoise(size_t *i, std::vector<std::string> filepath)
{
    if (_input.isKeyPressed(R_TYPE_KEY_D) && *i + 1 < filepath.size())
    {
        *i = *i + 1;
        _player->getObjectComp()->setTexture(filepath.at(*i));
    }
    if (_input.isKeyPressed(R_TYPE_KEY_Q) && *i > 0)
    {
        *i = *i - 1;
        _player->getObjectComp()->setTexture(filepath.at(*i));
    }

    if (_input.isInRect(_btnNext->getTextComp()->getRect()))
    {
        _btnNext->getTextComp()->setColor(GREEN);
        if (_input.isClicked(_btnNext->getTextComp()->getRect()))
            _gameState = GAME;
    }
    else
        _btnNext->getTextComp()->setColor(RED);

    if (_input.isInRect(_btnReturn->getTextComp()->getRect()))
    {
        _btnReturn->getTextComp()->setColor(GREEN);
        if (_input.isClicked(_btnReturn->getTextComp()->getRect()))
            _gameState = MENU;
    }
    else
        _btnReturn->getTextComp()->setColor(RED);

    if (_input.isInRect(_btnCreate->getTextComp()->getRect()))
        _btnCreate->getTextComp()->setColor(GREEN);
    else
        _btnCreate->getTextComp()->setColor(RED);
    if (_input.isInRect(_btnJoin->getTextComp()->getRect()))
        _btnJoin->getTextComp()->setColor(GREEN);
    else
        _btnJoin->getTextComp()->setColor(RED);
}

void Core::spaceShipChoise()
{
    initSpaceShipChoise();
    std::vector<std::string> filepath{"../sprites/GamePlay/ennemies/r-typesheet23.gif", "../sprites/GamePlay/ennemies/r-typesheet24.gif"};
    size_t i = 0;
    _player->getObjectComp()->setTexture(filepath.at(i));
    _player->getObjectComp()->setRefRect({0.0f, 0.0f, (float)_player->getObjectComp()->getTexture().width / 8, (float)_player->getObjectComp()->getTexture().height / 2});

    while (_gameState == SPACESHIP_CHOISE)
    {
        windowShouldClose();
        inputSpaceShipChoise(&i, filepath);
        drawSpaceShipChoise();
    }
}

void Core::drawSpaceShipChoise()
{
    _draw.beginDrawing();
    _draw.clearBackground(RAYWHITE);
    _draw.drawTexture(_backgroundMenu->getObjectComp()->getTexture(), {0, 0}, WHITE);
    _draw.drawText(_btnNext->getTextComp()->getText(), _btnNext->getPositionComp()->getPosition(), _btnNext->getTextComp()->getSize(), _btnNext->getTextComp()->getColor());
    _draw.drawText(_btnReturn->getTextComp()->getText(), _btnReturn->getPositionComp()->getPosition(), _btnReturn->getTextComp()->getSize(), _btnReturn->getTextComp()->getColor());
    _draw.drawText(_btnCreate->getTextComp()->getText(), _btnCreate->getPositionComp()->getPosition(), _btnCreate->getTextComp()->getSize(), _btnCreate->getTextComp()->getColor());
    _draw.drawText(_btnJoin->getTextComp()->getText(), _btnJoin->getPositionComp()->getPosition(), _btnJoin->getTextComp()->getSize(), _btnJoin->getTextComp()->getColor());
    _draw.drawText("appuyez sur Q/D pour passer au vaisseau suivant", {550, 150}, 20, RED);
    _draw.drawTexturePro(_player->getObjectComp()->getTexture(), _player->getObjectComp()->getRefRect(), {(float)_player->getPositionComp()->getPosition().x, (float)_player->getPositionComp()->getPosition().y, 200, 200}, {0, 0}, 0.0f, WHITE);
    _draw.endDrawing();
}

void Core::option()
{
    while (_gameState == OPTION)
    {
        windowShouldClose();
        if (_input.isKeyPressed(R_TYPE_KEY_O))
            setFps(getFps() - 1);
        if (_input.isKeyPressed(R_TYPE_KEY_P))
            setFps(getFps() + 1);
        _draw.beginDrawing();
        _draw.clearBackground(RAYWHITE);
        _draw.drawText("appuyez sur o pour diminuer les fps", {600, 300}, 20, RED);
        _draw.drawText("appuyez sur p pour augmenter les fps", {600, 400}, 20, RED);
        _draw.drawText(std::to_string(getFps()), {200, 300}, 20, RED);
        _draw.endDrawing();
    }
}

void Core::initGame()
{
    _audio.loadShotSound("../sprites/Blaster.ogg");

    _ennemy.push_back(reinterpret_cast<Ennemy *>(_ennemyFactory->create()));
    _camera = reinterpret_cast<rTypeCamera *>(_cameraFactory->create());
    _heart = reinterpret_cast<Heart *>(_heartFactory->create());
    _background = reinterpret_cast<Background *>(_backgroundFactory->create());

    _player->getObjectComp()->setRefRect({0.0f, 0.0f, (float)_player->getObjectComp()->getTexture().width / 8, (float)_player->getObjectComp()->getTexture().height / 2});
    _ennemy.at(0)->getObjectComp()->setRefRect({0.0f, 0.0f, (float)_ennemy.at(0)->getObjectComp()->getTexture().width / 8, (float)_ennemy.at(0)->getObjectComp()->getTexture().height / 2});
    _player->setKeys({R_TYPE_UP, R_TYPE_RIGHT, R_TYPE_DOWN, R_TYPE_LEFT});
}

void Core::inputGame()
{
    _draw.beginDrawing();
    _draw.clearBackground(RAYWHITE);
    _draw.drawTexture(_gameScreen, { 0, 0 }, WHITE);
    beginMode2d(_camera->getCameraComp()->getCamera2d());

    for (int i = 0; i < _player->getHealthComp()->getHp(); i++)
        _draw.drawTexture(_heart->getObjectComp()->getTexture(), {50 + 100 * i, 950}, WHITE);
    _draw.drawTextureRec(_player->getObjectComp()->getTexture(), _player->getObjectComp()->getRect(), _player->getPositionComp()->getPosition(), WHITE);
    for (std::size_t i = 0; i < _projectiles.size(); i++)
        _draw.drawTextureRec(_projectiles.at(i)->getObjectComp()->getTexture(), _projectiles.at(i)->getObjectComp()->getRect(), _projectiles.at(i)->getPositionComp()->getPosition(), WHITE);
    _draw.drawTextureRec(_ennemy.at(0)->getObjectComp()->getTexture(), _ennemy.at(0)->getObjectComp()->getRect(), _ennemy.at(0)->getPositionComp()->getPosition(), WHITE);
    _draw.drawRectangleLines({15, 40}, _player->getObjectComp()->getTexture().width, _player->getObjectComp()->getTexture().height, LIME);
    _draw.drawRectangleLines({15 + (int)_player->getObjectComp()->getRect().x, 40 + (int)_player->getObjectComp()->getRect().y}, (int)_player->getObjectComp()->getRect().width, (int)_player->getObjectComp()->getRect().height, RED);
    _draw.drawTextureRec(_player->getObjectComp()->getTexture(), _player->getObjectComp()->getRect(), _player->getPositionComp()->getPosition(), WHITE);
    _draw.drawTexture(_player->getObjectComp()->getTexture(), {15, 40}, WHITE);
    
    endMode2d();
    _draw.endDrawing();
}

void Core::game()
{
    initGame();
    while (_gameState == GAME)
    {
        windowShouldClose();
        _player->getAnimationComp()->animate(getFps(), _player->getObjectComp());
        _ennemy.at(0)->getAnimationComp()->animate(getFps(), _ennemy.at(0)->getObjectComp());
        _ennemy.at(0)->getAiComp()->play(_ennemy.at(0)->getPositionComp(), _ennemy.at(0)->getMovementsComp());

        inputGame();

        for (std::size_t i = 0; i < _projectiles.size(); i++)
        {
            _projectiles.at(i)->getAnimationComp()->animate(getFps(), _projectiles.at(i)->getObjectComp());
            _projectiles.at(i)->getMovementsComp()->move(_projectiles.at(i)->getPositionComp(), RIGHT);
        }

        deleteProjectiles(_projectiles);

        if (_input.isKeyDown(R_TYPE_KEY_W))
            _camera->getCameraComp()->setRotation(-30);
        else if (_input.isKeyDown(R_TYPE_KEY_X))
            _camera->getCameraComp()->setRotation(30);
        _draw.drawTexture(_background->getObjectComp()->getTexture(), _background->getPositionComp()->getPosition(), WHITE);
        drawGame();
    }

    for (std::size_t i = 0; i < _projectiles.size(); i++)
        _projectiles.at(i)->getObjectComp()->unloadTexture();

    unloadTexture(_ennemy.at(0)->getObjectComp()->getTexture());
    unloadTexture(_heart->getObjectComp()->getTexture());
    unloadTexture(_player->getObjectComp()->getTexture());

    _audio.unloadShotSound();
}

void Core::drawGame()
{
    _draw.beginDrawing();
    _draw.clearBackground(RAYWHITE);
    beginMode2d(_camera->getCameraComp()->getCamera2d());

    _draw.drawTexture(_background->getObjectComp()->getTexture(), _background->getPositionComp()->getPosition(), WHITE);
    for (int i = 0; i < _player->getHealthComp()->getHp(); i++)
        _draw.drawTexture(_heart->getObjectComp()->getTexture(), {50 + 100 * i, 950}, WHITE);
    _draw.drawTextureRec(_player->getObjectComp()->getTexture(), _player->getObjectComp()->getRect(), _player->getPositionComp()->getPosition(), WHITE);
    for (std::size_t i = 0; i < _projectiles.size(); i++)
        _draw.drawTextureRec(_projectiles.at(i)->getObjectComp()->getTexture(), _projectiles.at(i)->getObjectComp()->getRect(), _projectiles.at(i)->getPositionComp()->getPosition(), WHITE);
    _draw.drawTextureRec(_ennemy.at(0)->getObjectComp()->getTexture(), _ennemy.at(0)->getObjectComp()->getRect(), _ennemy.at(0)->getPositionComp()->getPosition(), WHITE);
    _draw.drawRectangleLines({15, 40}, _player->getObjectComp()->getTexture().width, _player->getObjectComp()->getTexture().height, LIME);
    _draw.drawRectangleLines({15 + (int)_player->getObjectComp()->getRect().x, 40 + (int)_player->getObjectComp()->getRect().y}, (int)_player->getObjectComp()->getRect().width, (int)_player->getObjectComp()->getRect().height, RED);
    _draw.drawTextureRec(_player->getObjectComp()->getTexture(), _player->getObjectComp()->getRect(), _player->getPositionComp()->getPosition(), WHITE);
    _draw.drawTexture(_player->getObjectComp()->getTexture(), {15, 40}, WHITE);

    endMode2d();
    _draw.endDrawing();
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

bool Core::windowShouldClose()
{
    if (WindowShouldClose())
        _gameState = CLOSE;
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

int Core::getMonitorHeight(int monitor)
{
    return GetMonitorHeight(monitor);
}

int Core::getMonitorWidth(int monitor)
{
    return GetMonitorWidth(monitor);
}

void Core::setWindowSize(int width, int height)
{
    SetWindowSize(width, height);
}

bool Core::isWindowFullscreen()
{
    return IsWindowFullscreen();
}

int Core::getCurrentMonitor()
{
    return GetCurrentMonitor();
}

void Core::initWindow(std::string name)
{
    InitWindow(_screenSize.screenWidth, _screenSize.screenHeight, name.c_str());
}

void Core::setConfigFlags(ConfigFlags configFlags)
{
    SetConfigFlags(configFlags);
}

void Core::toggleFullscreen()
{
    ToggleFullscreen();
}