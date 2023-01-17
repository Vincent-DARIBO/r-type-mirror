#ifndef _CORE_
#define _CORE_

#include <string>
#include <raylib.h>
#include "./Draw.hpp"
#include "./Input.hpp"
#include "../Entity/Player.hpp"
#include <vector>
#include <memory>

class Core
{
private:
    int _screenWidth;
    int _screenHeight;
    int _fps;
    std::string _name;
    Draw _draw;
    Input _input;
    int _keyUp;
    int _keyRight;
    int _keyDown;
    int _keyLeft;
protected:
    Player _player;
public:
    Core(/* args */);
    ~Core();
    Core(int screenWidth, int screenHeight, std::string name, int fps);
    void setFps(int fps);
    int getFps();
    int getScreenWidth();
    int getScreenHeight();
    bool windowShouldClose();
    void closeWindow();
    Draw getDraw();
    Input getInput();
    void unloadTexture(Texture2D texture);
    void setInputs(int keyUp, int keyRight, int keyDown, int keyLeft);
    Vector4 getInputs();
};

#endif