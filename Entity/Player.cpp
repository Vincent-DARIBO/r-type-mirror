#include "./Player.hpp"

Player::Player(/* args */)
{
}

Player::~Player()
{
}

void Player::setKeys(Keys keys)
{
    _keys = keys;
}

Keys Player::getKeys()
{
    return _keys;
}