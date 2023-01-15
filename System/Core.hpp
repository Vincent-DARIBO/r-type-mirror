#ifndef _CORE_
#define _CORE_

#include <string>
#include <raylib.h>
#include "./Draw.hpp"

class Core
{
private:
    int _screenWidth;
    int _screenHeight;
    int _fps;
    std::string _name;
    Draw _draw;
public:
    Core(/* args */);
    ~Core();
    Core(int screenWidth, int screenHeight, std::string name, int fps);
    void setFps(int fps);
    int getScreenWidth();
    int getScreenHeight();
    bool windowShouldClose();
    void closeWindow();
    Draw getDraw();
    void unloadTexture(Texture2D texture);
};

#endif