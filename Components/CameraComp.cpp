#include "./CameraComp.hpp"

Components::CameraComp::CameraComp(Vector2 target, Vector2 offset, float rotation, float zoom)
{
    _componentType = ComponentTypes::CAMERACOMP;
    _camera.target = target;
    _camera.offset = offset;
    _camera.rotation = rotation;
    _camera.zoom = zoom;
}

Components::CameraComp::~CameraComp()
{
}

float Components::CameraComp::getRotation()
{
    return _camera.rotation;
}

void Components::CameraComp::setRotation(float rotation)
{
    _camera.rotation = rotation;
}

Camera2D &Components::CameraComp::getCamera2d()
{
    return _camera;
}