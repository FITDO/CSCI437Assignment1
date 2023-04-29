#include "Weapon.h"

#include "stdlib.h"

Weapon::Weapon (std::string name , int damage , int minDamage)
: Item (name) ,
  damage_ (damage) ,
  minDamage_ (minDamage)
{

}

int Weapon::attack (void)
{
    return rand() % damage_ + minDamage_;
}

std::string Weapon::getDescription (void)
{
    return "Name: " + this->name_ + "\nBaseDamage: " + std::to_string ( this->minDamage_ ) + "\nDamage: " + std::to_string ( this->damage_ ) + "\n";
}

void Weapon::giveToPlayer (Player * player)
{
    player->setWeapon (this);
}