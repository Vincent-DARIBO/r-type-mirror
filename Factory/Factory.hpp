#ifndef _FACTORY_
#define _FACTORY_

#include "../Entity/Entity.hpp"

class Factory
{
private:
    /* data */
public:
    Factory(/* args */);
    ~Factory();
    virtual Entity* create() const = 0;
};

#endif