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
    _screenWidth = _screenWidth;
    InitWindow(screenWidth, screenHeight, name.c_str());
    SetTargetFPS(fps);
}

void Core::setFps(int fps)
{
    _fps = fps;
    SetTargetFPS(_fps);
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

bool Core::windowShouldClose()
{
    return WindowShouldClose();
}

void Core::closeWindow()
{
    CloseWindow();
}

void unloadTexture(Texture2D texture)
{
    UnloadTexture(texture);
}