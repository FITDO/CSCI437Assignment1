#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <string>

#include "iostream"

class Entity
{
protected:

    std::string name_;
    int health_;
    int maxHealth_;

    Entity (std::string name , int health);
    
public:

    std::string getName (void);

    int getHealth (void);

    int getMaxHealth (void);

    virtual void takeDamage (int damage) = 0;

    virtual int attack (void) = 0;
};

#endif