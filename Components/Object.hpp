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
        Rectangle _refRect;
    public:
        Object(/* args */);
        Object(std::string path);
        Object(std::string path, Rectangle rect);
        ~Object();
        void setTexture(std::string path);
        void setRect(Rectangle rect);
        void setRefRect(Rectangle refRect);
        Rectangle getRect();
        Rectangle getRefRect();
        Texture2D getTexture();
        void unloadTexture();
    };
}

#endif