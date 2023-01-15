#ifndef _OBJECT_
#define _OBJECT_

#include "./IComponent.hpp"

namespace Components
{
    class Object : public IComponent
    {
    private:
        Texture2D _texture;
        Rectangle _rect;
    public:
        Object(/* args */);
        ~Object();
        void setTexture(std::string path);
        void setRect(Rectangle rect);
        Rectangle getRect();
        Texture2D getTexture();
    };
}

#endif