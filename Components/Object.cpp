#include "./Object.hpp"

Components::Object::Object(/* args */)
{
    _componentType = ComponentTypes::OBJECT;
}

Components::Object::Object(std::string path)
{
    _componentType = ComponentTypes::OBJECT;
    _texture = LoadTexture(path.c_str());
}

Components::Object::Object(std::string path, Rectangle rect)
{
    _componentType = ComponentTypes::OBJECT;
    _texture = LoadTexture(path.c_str());
    _rect = rect;
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
    _rect = rect;
}

void Components::Object::setRefRect(Rectangle refRect)
{
    _refRect = refRect;
    _rect = _refRect;
}

Rectangle Components::Object::getRect()
{
    return _rect;
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