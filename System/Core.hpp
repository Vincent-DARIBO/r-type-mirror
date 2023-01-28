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
#include "../Factory/PlayerFactory.hpp"
#include "../Factory/ProjectilesFactory.hpp"
#include "../Factory/EnnemyFactory.hpp"
#include "../Factory/CameraFactory.hpp"
#include "../Factory/HeartFactory.hpp"
#include "../Factory/ButtonFactory.hpp"
#include "../Factory/BackgroundFactory.hpp"
#include "../Components/CameraComp.hpp"
#include "../Components/Ai.hpp"
#include "../Components/Health.hpp"

enum gameState
{
    CLOSE,
    MENU,
    OPTION,
    SPACESHIP_CHOISE,
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
    gameState _gameState;
    Button *_btnNext;
    Button *_btnReturn;
    Button *_btnCreate;
    Button *_btnJoin;
    Background *_backgroundMenu;
    std::unique_ptr<Factory> _playerFactory;
    std::unique_ptr<Factory> _projectileFactory;
    std::unique_ptr<Factory> _ennemyFactory;
    std::unique_ptr<Factory> _cameraFactory;
    std::unique_ptr<Factory> _heartFactory;
    std::unique_ptr<Factory> _buttonFactory;
    std::unique_ptr<Factory> _backgroundFactory;
    std::vector<Ennemy *> _ennemy;
    rTypeCamera *_camera;
    std::vector<Projectiles *> _projectiles;
    Heart *_heart;
    Background *_background;

protected:
    Player *_player;

public:
    ~Core();
    Core(ScreenSize screenSize, std::string name, int fps);
    void menu();
    void initGame();
    void game();
    void drawGame();
    void option();
    ScreenSize getScreenSize();
    // Draw getDraw();
    Input getInput();
    Audio &getAudio();
    int getFps();
    void setFps(int fps);
    void beginMode2d(Camera2D &camera);
    void endMode2d();
    bool windowShouldClose();
    void closeWindow();
    void setConfigFlags(ConfigFlags configFlags);
    void initAudioDevice();
    void initWindow(std::string name);
    void closeAudioDevice();
    void unloadTexture(Texture2D texture);
    void spaceShipChoise();
    // Vector4 getInputs();
    // void setInputs(int keyUp, int keyRight, int keyDown, int keyLeft);
    void deleteProjectiles(std::vector<Projectiles *> &projectiles);
    void handleState();
    void drawSpaceShipChoise();
    void initSpaceShipChoise();
};

#endif