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

// std::vector<Components::Projectiles> Core::getProjectiles()
// {
//     return _projectiles;
// }

// void Core::addProjectiles(vector2int pos)
// {
//     Components::Projectiles projectile;

//     _projectiles.push_back(projectile);
// }