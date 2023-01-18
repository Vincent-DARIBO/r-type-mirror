#ifndef _CORE_
#define _CORE_

#include <string>
#include <raylib.h>
#include "./Draw.hpp"
#include "./Input.hpp"
#include "../Entity/Player.hpp"
#include <vector>
#include <memory>
#include "./ScreenSize.hpp"

class Core
{
private:
    ScreenSize _screenSize;
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
    Core(ScreenSize screenSize, std::string name, int fps);
    void setFps(int fps);
    int getFps();
    ScreenSize getScreenSize();
    bool windowShouldClose();
    void closeWindow();
    Draw getDraw();
    Input getInput();
    void unloadTexture(Texture2D texture);
    void setInputs(int keyUp, int keyRight, int keyDown, int keyLeft);
    Vector4 getInputs();
    void deleteProjectiles(std::vector<Projectiles *> &projectiles);
};

#endif