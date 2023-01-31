#include "./CameraFactory.hpp"

CameraFactory::CameraFactory(/* args */)
{
}

CameraFactory::~CameraFactory()
{
}

Entity *CameraFactory::create() const 
{
    Vector2 pos = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    Vector2 pos2 = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    rTypeCamera *camera = new rTypeCamera();
    Components::CameraComp cameraComp(pos, pos2, 0.0f, 1.0f);
    camera->addComp(std::make_shared<Components::CameraComp>(cameraComp));
    return camera;
}