#include "./Object.hpp"

Components::Object::Object(/* args */)
{
    _componentType = ComponentTypes::OBJECT;
}

Components::Object::Object(std::string path)
{
    _componentType = ComponentTypes::OBJECT;
    setTexture(path);
}

Components::Object::~Object()
{
}
void Components::Object::setTexture(std::string path)
{
    _texture = LoadTexture(path.c_str());
}

void Components::Object::setRect(Rectangle rect)
{
    _currentRect = rect;
}

void Components::Object::setRefRect(Rectangle refRect)
{
    _refRect = refRect;
    _currentRect = _refRect;
}

Rectangle Components::Object::getRect()
{
    return _currentRect;
}

Rectangle Components::Object::getRefRect()
{
    return _refRect;
}

Texture2D Components::Object::getTexture()
{
    return _texture;
}

void Components::Object::unloadTexture()
{
    UnloadTexture(_texture);
}