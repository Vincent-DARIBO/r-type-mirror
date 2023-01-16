#include "./Animation.hpp"

Components::Animation::Animation(/* args */)
{
    _componentType = ComponentTypes::ANIMATION;
}

Components::Animation::~Animation()
{
}

void Components::Animation::setFrames(int currentFrame, int framesCounter, int framesSpeed, int limitFrame)
{
    _currentFrame = currentFrame;
    _framesCounter = framesCounter;
    _framesSpeed = framesSpeed;
    _limitFrame = limitFrame;
}

void Components::Animation::animate(int fps, Object &object)
{
    _framesCounter++;

    if (_framesCounter >= (fps / _framesSpeed))
    {
        _framesCounter = 0;
        _currentFrame++;

        if (_currentFrame >= _limitFrame)
            _currentFrame = 0;

        object.setRect({(float)_currentFrame * (float)object.getTexture().width / 8, object.getRect().y, object.getRect().width, object.getRect().height});
    }
}