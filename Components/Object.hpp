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
        Texture2D getTexture();
        void setRect(Rectangle rect);
        Rectangle getRect();
        void setRefRect(Rectangle refRect);
        Rectangle getRefRect();
        void unloadTexture();
    };
}

#endif