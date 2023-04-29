#include "Player.h"

Player::Player (std::string name , int health , Armor * armor , Weapon * weapon)
: Entity (name , health)
{
    this->armor_ = armor;
    this->weapon_ = weapon;
}

void Player::takeDamage (int damage)
{
    if (armor_->getDefense () >= damage)
    {
        std::cout << this->name_ << "took no damage." << std::endl;
    }
    else
    {
        int totalDamage = damage - armor_->getDefense ();

        this->health_ -= totalDamage;

        std::cout << this->name_ << " took " << totalDamage << " damage!" << std::endl;
    }
}

int Player::attack (void)
{
    std::cout << "You ready your " << this->weapon_->getName () << std::endl;
    return this->weapon_->attack ();
}

void Player::setArmor (Armor * armor)
{
    this->armor_ = armor;
}

void Player::setWeapon (Weapon * weapon)
{
    this->weapon_ = weapon;
}