#include "./Core.hpp"

Core::Core(/* args */)
{
}

Core::~Core()
{
}

Core::Core(int screenWidth, int screenHeight, std::string name, int fps)
{
    _screenHeight = screenHeight;
    _screenWidth = screenWidth;
    InitWindow(_screenWidth, _screenHeight, name.c_str());
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

int Core::getScreenWidth()
{
    return _screenWidth;
}
int Core::getScreenHeight()
{
    return _screenHeight;
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
    return {_keyUp, _keyRight, _keyDown, _keyLeft};
}