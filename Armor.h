#ifndef _ARMOR_H_
#define _ARMOR_H_

#include <string>

#include "Item.h"

class Armor : public Item
{
private:

    std::string name_;
    int defense_;

public:

    Armor (std::string name , int defense);

    int getDefense (void);

    std::string getDescription (void);

    void giveToPlayer (Player * player);
};

#endif