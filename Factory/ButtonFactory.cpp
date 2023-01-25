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
    Components::Position posComp({0, 0});
    Components::Text textComp;
    button->addComp(std::make_shared<Components::Position>(posComp));
    button->addComp(std::make_shared<Components::Text>(textComp));
    button->getTextComp()->setSize(40);
    button->getTextComp()->setColor(RED);

    return button;
}