#include "./Core.hpp"
#define MAX_INPUT_CHARS 9

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
    _playerFactory = std::make_unique<PlayerFactory>();
    _projectileFactory = std::make_unique<ProjectilesFactory>();
    _ennemyFactory = std::make_unique<EnnemyFactory>();
    _cameraFactory = std::make_unique<CameraFactory>();
    _heartFactory = std::make_unique<HeartFactory>();
    _player = reinterpret_cast<Player *>(_playerFactory->create());
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
        if (IsKeyDown(R_TYPE_KEY_T))
        {
            _gameState = SPACESHIP_CHOISE;
            spaceShipChoise();
        }
        if (IsKeyDown(R_TYPE_KEY_V))
        {
            _gameState = SERVEUR_CONNECTION;
            serveurConnection();
        }
        _draw.beginDrawing();
        _draw.clearBackground(RAYWHITE);
        _draw.drawText("menu\nappuyez sur e pour passer au jeu", {600, 300}, 20, RED);
        _draw.drawText("appuyez sur r pour passer aux options", {600, 400}, 20, RED);
        _draw.drawText("appuyez sur v pour passer aux serveurConnection", {700, 500}, 20, RED);
        _draw.drawText("appuyez sur t pour choisir votre vaisseau", {800, 600}, 20, RED);
        _draw.endDrawing();
    }
}

void Core::spaceShipChoise()
{
    std::vector<std::string> filepath{"../sprites/r-typesheet23.gif", "../sprites/r-typesheet24.gif"};
    size_t i = 0;
    _player->getPositionComp()->setPosition({300, 300});
    _player->getObjectComp()->setTexture(filepath.at(i));
    _player->getObjectComp()->setRefRect({0.0f, 0.0f, (float)_player->getObjectComp()->getTexture().width / 8, (float)_player->getObjectComp()->getTexture().height / 2});
    while (!windowShouldClose() && _gameState == SPACESHIP_CHOISE)
    {
        if (IsKeyPressed(R_TYPE_KEY_D) && i + 1 < filepath.size())
        {
            i++;
            _player->getObjectComp()->setTexture(filepath.at(i));
        }
        if (IsKeyPressed(R_TYPE_KEY_Q) && i > 0)
        {
            i--;
            _player->getObjectComp()->setTexture(filepath.at(i));
        }
        if (IsKeyPressed(R_TYPE_ENTER))
        {
            _gameState = GAME;
            game();
        }
        _draw.beginDrawing();
        _draw.clearBackground(RAYWHITE);
        _draw.drawRectangle({300, 300}, 200, 200, BLACK);
        _draw.drawText("appuyez sur Q/D pour passer au vaisseau suivant", {600, 200}, 20, RED);
        _draw.drawText("appuyez sur enter pour passer au jeu", {1300, 900}, 20, RED);
        _draw.drawTexturePro(_player->getObjectComp()->getTexture(), _player->getObjectComp()->getRefRect(), {(float)_player->getPositionComp()->getPosition().x, (float)_player->getPositionComp()->getPosition().y, 200, 200}, {0, 0}, 0.0f, WHITE);
        _draw.endDrawing();
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
        _draw.beginDrawing();
        _draw.clearBackground(RAYWHITE);
        _draw.drawText("appuyez sur o pour diminuer les fps", {600, 300}, 20, RED);
        _draw.drawText("appuyez sur p pour augmenter les fps", {600, 400}, 20, RED);
        _draw.drawText(std::to_string(getFps()), {200, 300}, 20, RED);
        _draw.endDrawing();
    }
}

std::string Core::createTextInput(std::__1::string name, float x, float y)
{
    // Set variables
    int letterCount = 0;
    Rectangle textBox = {x, y, 600, 50};
    bool mouseOnText = false;
    int framesCounter = 0;

    // Check if the mouse is on text
    if (CheckCollisionPointRec(GetMousePosition(), textBox))
        mouseOnText = true;
    else
        mouseOnText = false;

    // Récupère les charactère
    if (mouseOnText)
    {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
            {
                name[letterCount] = (char)key;
                name[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
                letterCount++;
            }

            key = GetCharPressed(); // Check next character in the queue
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            letterCount--;
            if (letterCount < 0)
                letterCount = 0;
            name[letterCount] = '\0';
        }
    }
    else
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    if (mouseOnText)
        framesCounter++;
    else
        framesCounter = 0;
    DrawRectangleRec(textBox, BLUE);
    if (mouseOnText)
        DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, YELLOW);
    else
        DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKBLUE);

    _draw.drawText(name, {(int)textBox.x + 5, (int)textBox.y + 8}, 40, WHITE);

    if (mouseOnText)
    {
        if (letterCount < MAX_INPUT_CHARS)
        {
            // Draw blinking underscore char
            if (((framesCounter / 20) % 2) == 0)
                _draw.drawText("_", {(int)textBox.x + 8, (int)textBox.y + 12}, 40, WHITE);
        }
        else
            DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, RED);
    }
    return (name);
}

void Core::serveurConnection()
{
    _serveurConnection = LoadTexture("sprites/Menus/ServeurConnectionBg-2.png");

    while (!windowShouldClose() && _gameState == SERVEUR_CONNECTION)
    {
        char username[MAX_INPUT_CHARS + 1] = "\0";
        char serverIp[MAX_INPUT_CHARS + 1] = "\0";

        BeginDrawing();
        ClearBackground(RAYWHITE);
        _draw.drawTexture(_serveurConnection, {20, 90}, WHITE);
        createTextInput(username, 470, 550);
        createTextInput(serverIp, 470, 796);
        EndDrawing();
    }
}

void Core::initGame()
{
    _audio.loadShotSound("../assets/Blaster.ogg");

    _ennemy.push_back(reinterpret_cast<Ennemy *>(_ennemyFactory->create()));
    _camera = reinterpret_cast<rTypeCamera *>(_cameraFactory->create());
    _heart = reinterpret_cast<Heart *>(_heartFactory->create());

    _player->getObjectComp()->setRefRect({0.0f, 0.0f, (float)_player->getObjectComp()->getTexture().width / 8, (float)_player->getObjectComp()->getTexture().height / 2});
    _ennemy.at(0)->getObjectComp()->setRefRect({0.0f, 0.0f, (float)_ennemy.at(0)->getObjectComp()->getTexture().width / 8, (float)_ennemy.at(0)->getObjectComp()->getTexture().height / 2});
    _player->setKeys({R_TYPE_UP, R_TYPE_RIGHT, R_TYPE_DOWN, R_TYPE_LEFT});
}

void Core::drawGame()
{
    _draw.beginDrawing();
    _draw.clearBackground(RAYWHITE);
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
    while (!windowShouldClose() && _gameState == GAME)
    {
        _player->getAnimationComp()->animate(getFps(), _player->getObjectComp());
        _ennemy.at(0)->getAnimationComp()->animate(getFps(), _ennemy.at(0)->getObjectComp());
        _ennemy.at(0)->getAiComp()->play(_ennemy.at(0)->getPositionComp(), _ennemy.at(0)->getMovementsComp());

        _input.handler(_player, _projectiles, _projectileFactory, getScreenSize(), getAudio());

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

    unloadTexture(_ennemy.at(0)->getObjectComp()->getTexture());
    unloadTexture(_heart->getObjectComp()->getTexture());
    unloadTexture(_player->getObjectComp()->getTexture());

    _audio.unloadShotSound();
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

// Draw Core::getDraw()
// {
//     return _draw;
// }

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

// void Core::setInputs(int keyUp, int keyRight, int keyDown, int keyLeft)
// {
//     _keyUp = keyUp;
//     _keyRight = keyRight;
//     _keyDown = keyDown;
//     _keyLeft = keyLeft;
// }

// Vector4 Core::getInputs()
// {
//     return {(float)_keyUp, (float)_keyRight, (float)_keyDown, (float)_keyLeft};
// }

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