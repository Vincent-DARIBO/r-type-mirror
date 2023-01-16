#ifndef _ANIMATE_
#define _ANIMATE_

#include "./IComponent.hpp"
#include "./Object.hpp"

namespace Components
{
    class Animation : public IComponent
    {
    private:
        int _currentFrame;
        int _framesCounter;
        int _framesSpeed;
        int _limitFrame;

    public:
        Animation(/* args */);
        ~Animation();
        void setFrames(int _currentFrame, int _framesCounter, int _framesSpeed, int _limitFrame);
        void animate(int fps, Object &object);
    };
}

#endif