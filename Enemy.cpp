#include "Enemy.h"

Enemy::Enemy (std::string name , int health , int defense , int damage  , int mindamage , std::string startMessage , std::string attackMessage , std::string deathMessage)
: Entity (name , health) ,
    defense_ (defense) ,
    damage_ (damage) ,
    minDamage_ (mindamage) , 
    startMessage_ (startMessage) ,
    attackMessage_ (attackMessage) ,
    deathMessage_ (deathMessage)
{

}

std::string Enemy::getStartMessage (void)
{
    return this->startMessage_;
}

std::string Enemy::getDeathMessage (void)
{
    return this->deathMessage_;
}

void Enemy::takeDamage (int damage)
{

    if (defense_ >= damage)
    {
        std::cout << this->name_ << "took no damage." << std::endl;
    }
    else
    {
        int totalDamage = damage - defense_;

        this->health_ -= totalDamage;

        std::cout << this->name_ << " took " << totalDamage << " damage!" << std::endl;
    }

}

int Enemy::attack (void)
{
    std::cout << attackMessage_ << std::endl;
    return rand() % damage_ + minDamage_;
}