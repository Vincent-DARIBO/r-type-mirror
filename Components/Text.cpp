#include "./Text.hpp"

Components::Text::Text(/* args */)
{
    _componentType = ComponentTypes::TEXT;
}

Components::Text::~Text()
{
}

void Components::Text::setText(std::string text)
{
    _text = text;
}

std::string Components::Text::getText()
{
    return _text;
}

void Components::Text::setSize(int size)
{
    _size = size;
}

int Components::Text::getSize()
{
    return _size;
}

void Components::Text::setRect(Rectangle rect)
{
    _rect = rect;
}

Rectangle Components::Text::getRect()
{
    return _rect;
}

void Components::Text::setColor(Color color)
{
    _color = color;
}

Color Components::Text::getColor()
{
    return _color;
}