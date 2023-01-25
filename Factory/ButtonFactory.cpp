#include "./ButtonFactory.hpp"

ButtonFactory::ButtonFactory(/* args */)
{
}

ButtonFactory::~ButtonFactory()
{
}

Entity *ButtonFactory::create() const 
{
    Button *button = new Button();
    Components::Position posComp({0,0});
    button->addComp(std::make_shared<Components::Position>(posComp));
    return button;
}