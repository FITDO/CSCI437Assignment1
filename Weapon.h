#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <string>

#include "Item.h"

class Weapon : public Item
{
private:
    int damage_;
    int minDamage_;
    
public:

    Weapon (std::string name , int damage , int minDamage);

    int attack (void);

    std::string getDescription (void);

    void giveToPlayer (Player * player);
};

#endif