#ifndef _TEXT_
#define _TEXT_

#include "./IComponent.hpp"

namespace Components
{
    class Text : public IComponent
    {
    private:
        std::string _text;
        int _size;
        Rectangle _rect;
        Color _color;
    public:
        Text(/* args */);
        ~Text();
        void setText(std::string text);
        void setSize(int size);
        std::string getText();
        int getSize();
        void setRect(Rectangle rect);
        Rectangle getRect();
        void setColor(Color color);
        Color getColor();
    };
}

#endif