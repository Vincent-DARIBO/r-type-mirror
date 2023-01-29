#ifndef BUTTON_FACTORY
#define BUTTON_FACTORY

#include "./Factory.hpp"
#include "../Entity/Button.hpp"

class ButtonFactory : public Factory
{
private:
    /* data */
public:
    ButtonFactory(/* args */);
    ~ButtonFactory();
    Entity *create() const override;
};

#endif