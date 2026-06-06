#include "player.h"

void Player::SetName(const std::string& newName)
{
    name = newName;
}

void Player::SetLocation(const std::string& newLocation)
{
    location = newLocation;
}

const std::string& Player::GetName() const
{
    return name;
}

const std::string& Player::GetLocation() const
{
    return location;
}