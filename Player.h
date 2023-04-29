#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"

class Armor;
class Weapon;


class Player : public Entity
{
protected:

    Armor * armor_;
    Weapon * weapon_;

public:

    Player (std::string name , int health , Armor * armor , Weapon * weapon);

    void takeDamage (int damage);

    int attack (void);

    void setArmor (Armor * armor);

    void setWeapon (Weapon * weapon);
};

#include "Armor.h"
#include "Weapon.h"

#endif