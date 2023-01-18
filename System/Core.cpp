#include "./Core.hpp"

Core::Core(/* args */)
{
}

Core::~Core()
{
}

Core::Core(ScreenSize screenSize, std::string name, int fps)
{
    _screenSize = screenSize;
    InitWindow(_screenSize.screenWidth, _screenSize.screenHeight, name.c_str());
    _fps = fps;
    SetTargetFPS(_fps);
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
    for (std::size_t i = 0; i < projectiles.size(); i++) {
        if (projectiles.at(i)->getPositionComp()->getPosition().x >= _screenSize.screenWidth || projectiles.at(i)->getPositionComp()->getPosition().y >= _screenSize.screenHeight) {
            projectiles.at(i)->getObjectComp()->unloadTexture();
            projectiles.erase(projectiles.begin() + i);
        }
    }
}