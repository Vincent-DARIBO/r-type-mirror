#ifndef _CORE_
#define _CORE_

#include <string>
#include <raylib.h>
#include <vector>
#include <memory>
#include "./Draw.hpp"
#include "./Input.hpp"
#include "../Entity/Player.hpp"
#include "./ScreenSize.hpp"
#include "./Audio.hpp"

enum gameState
{
    MENU,
    GAME,
};

class Core
{
private:
    ScreenSize _screenSize;
    int _fps;
    std::string _name;
    Draw _draw;
    Input _input;
    Audio _audio;
    int _keyUp;
    int _keyRight;
    int _keyDown;
    int _keyLeft;
    gameState _gameState;

protected:
    Player _player;

public:
    ~Core();
    Core(ScreenSize screenSize, std::string name, int fps);
    void menu();
    void game();
    ScreenSize getScreenSize();
    Draw getDraw();
    Input getInput();
    Vector4 getInputs();
    Audio getAudio();
    int getFps();
    void setFps(int fps);
    void beginMode2d(Camera2D camera);
    void endMode2d();
    bool windowShouldClose();
    void closeWindow();
    void initAudioDevice();
    void closeAudioDevice();
    void unloadTexture(Texture2D texture);
    void setInputs(int keyUp, int keyRight, int keyDown, int keyLeft);
    void deleteProjectiles(std::vector<Projectiles *> &projectiles);
};

#endif