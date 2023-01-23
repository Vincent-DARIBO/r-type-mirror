#include "./Position.hpp"

Components::Position::Position(/* args */)
{
    _componentType = ComponentTypes::POSITION;
}

Components::Position::Position(Vector2Int pos)
{
    _pos.x = pos.x;
    _pos.y = pos.y;
    _componentType = ComponentTypes::POSITION;
}

Components::Position::~Position()
{
}

void Components::Position::setPosition(Vector2Int pos)
{
    _pos.x = pos.x;
    _pos.y = pos.y;
}

Vector2Int Components::Position::getPosition()
{
    return _pos;
}