#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Entity.h"

#include <stdlib.h>

class Enemy : public Entity
{
protected:

    int defense_;
    int damage_;
    int minDamage_;
    std::string startMessage_;
    std::string attackMessage_;
    std::string deathMessage_;

public:

    Enemy (std::string name , int health , int defense , int damage  , int mindamage , std::string startMessage , std::string attackMessage , std::string deathMessage);

    std::string getStartMessage (void);

    std::string getDeathMessage (void);

    void takeDamage (int damage);

    int attack (void);
};

#endif