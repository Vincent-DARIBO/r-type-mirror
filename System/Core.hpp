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
#include "../Components/CameraComp.hpp"
#include "../Components/Ai.hpp"
#include "../Components/Health.hpp"

enum gameState
{
    CLOSE,
    MENU,
    OPTION,
    WELCOME_SPACESHIP,
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
    // int _keyUp;
    // int _keyRight;
    // int _keyDown;
    // int _keyLeft;
    gameState _gameState;
    std::unique_ptr<Factory> _playerFactory;
    std::unique_ptr<Factory> _projectileFactory;
    std::unique_ptr<Factory> _ennemyFactory;
    std::unique_ptr<Factory> _cameraFactory;
    std::unique_ptr<Factory> _heartFactory;
    std::vector<Ennemy *> _ennemy;
    rTypeCamera *_camera;
    std::vector<Projectiles *> _projectiles;
    Heart *_heart;


protected:
    Player *_player;
    Texture2D _welcomeToYourSpaceshipMenu;
    Texture2D _welcomeToYourSpaceshipMenuButton;

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
    void initAudioDevice();
    void closeAudioDevice();
    void unloadTexture(Texture2D texture);
    void spaceShipChoise();
    void welcomeToYourSpaceship();
    // Vector4 getInputs();
    // void setInputs(int keyUp, int keyRight, int keyDown, int keyLeft);
    void deleteProjectiles(std::vector<Projectiles *> &projectiles);
};

#endif