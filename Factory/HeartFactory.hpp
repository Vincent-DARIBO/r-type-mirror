#ifndef HEART_FACTORY
#define HEART_FACTORY

#include "./Factory.hpp"
#include "../Entity/Heart.hpp"

class HeartFactory : public Factory
{
private:
    /* data */
public:
    HeartFactory(/* args */);
    ~HeartFactory();
    Entity *create() const override;
};

#endif