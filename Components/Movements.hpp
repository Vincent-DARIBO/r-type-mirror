#include "./IComponent.hpp"

namespace Components
{
    class Movements : public IComponent
    {
    private:
        int _speed;

    public:
        Movements(/* args */);
        ~Movements();
        void setSpeed(int speed);
        int getSpeed();
    };
}