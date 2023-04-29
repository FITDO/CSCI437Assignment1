#include "Armor.h"

Armor::Armor (std::string name , int defense)
: Item (name) ,
    defense_ (defense)
{

}



int Armor::getDefense (void)
{
    return this->defense_;
}

std::string Armor::getDescription (void)
{
    return "Name: " + this->name_ + "\nDefense: " + std::to_string( this->defense_ ) + "\n";
}

void Armor::giveToPlayer (Player * player)
{
    player->setArmor (this);
}