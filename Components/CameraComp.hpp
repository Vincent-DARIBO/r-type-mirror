#ifndef CAMERA_COMPONENT
#define CAMERA_COMPONENT

#include "./IComponent.hpp"

namespace Components
{
    class CameraComp : public IComponent
    {
    private:
        Camera2D _camera;

    public:
        CameraComp(Vector2 target, Vector2 offset, float rotation, float zoom);
        ~CameraComp();
        float getRotation();
        void setRotation(float rotation);
        Camera2D &getCamera2d();

    };
}
#endif