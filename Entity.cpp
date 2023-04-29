#include "Entity.h"

Entity::Entity (std::string name , int health)
: name_ (name) ,
    maxHealth_ (health) ,
    health_ (health)
{
    if (health == 0)
    {
        this->maxHealth_ = 100;
        this->health_ = 100;
    }
}

std::string Entity::getName (void)
{
    return this->name_;
}

int Entity::getHealth (void)
{
    return this->health_;
}

int Entity::getMaxHealth (void)
{
    return this->maxHealth_;
}