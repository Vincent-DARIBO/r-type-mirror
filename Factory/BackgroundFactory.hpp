#ifndef _BACKGROUND_FACTORY_
#define _BACKGROUND_FACTORY_

#include "./Factory.hpp"
#include "../Entity/Background.hpp"

class BackgroundFactory : public Factory
{
private:
    /* data */
public:
    BackgroundFactory(/* args */);
    ~BackgroundFactory();
    Entity *create() const override;
};

#endif