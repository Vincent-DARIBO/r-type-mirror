#include "./HeartFactory.hpp"

HeartFactory::HeartFactory(/* args */)
{
}

HeartFactory::~HeartFactory()
{
}

Entity *HeartFactory::create() const 
{
    return new Heart();
}