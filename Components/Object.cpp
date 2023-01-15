#include "./Object.hpp"

Components::Object::Object(/* args */)
{
    _componentType = ComponentTypes::OBJECT;
}

Components::Object::~Object()
{
}
void Components::Object::setTexture(std::string path)
{
    _texture = LoadTexture(path.c_str());
}

Texture2D Components::Object::getTexture()
{
    return _texture;
}
void Components::Object::setRect(Rectangle rect)
{
    _rect = rect;
}

Rectangle Components::Object::getRect()
{
    return _rect;
}