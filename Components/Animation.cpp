#include "./Animation.hpp"

Components::Animation::Animation(/* args */)
{
    _componentType = ComponentTypes::ANIMATION;
}

Components::Animation::Animation(int currentFrame, int framesCounter, int framesSpeed, int limitFrame)
{
    _componentType = ComponentTypes::ANIMATION;
    _currentFrame = currentFrame;
    _framesCounter = framesCounter;
    _framesSpeed = framesSpeed;
    _limitFrame = limitFrame;
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

void Components::Animation::animate(int fps, std::shared_ptr<Object> object)
{
    _framesCounter++;

    if (_framesCounter >= (fps / _framesSpeed))
    {
        _framesCounter = 0;
        _currentFrame++;

        if (_currentFrame >= _limitFrame)
            _currentFrame = 0;

        // object->setRect({ object->getRefRect().x + ((float)_currentFrame * (float)object->getTexture().width / _limitFrame), object->getRect().y, object->getRect().width, object->getRect().height});
        object->setRect({ object->getRefRect().x + ((float)_currentFrame * (float)object->getRefRect().width), object->getRect().y, object->getRect().width, object->getRect().height});
    }
}