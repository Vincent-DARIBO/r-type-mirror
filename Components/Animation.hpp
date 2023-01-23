#ifndef _ANIMATE_
#define _ANIMATE_

#include "./IComponent.hpp"
#include "./Object.hpp"
#include <memory>

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
        Animation(int _framesSpeed, int _limitFrame);
        ~Animation();
        void setFrames(int _framesSpeed, int _limitFrame);
        void animate(int fps, std::shared_ptr<Object> object);
    };
}

#endif