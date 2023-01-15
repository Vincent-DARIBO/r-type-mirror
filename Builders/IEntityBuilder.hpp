#ifndef IENTITYBUILDER_HPP_
#define IENTITYBUILDER_HPP_

#include "../Entity/Entity.hpp"

class IEntityBuilder
{
public:
    ~IEntityBuilder() = default;
    // virtual void reset(position_t position) = 0;
    virtual void addComps() = 0;
    virtual Entity &getEntity() = 0;
};

#endif