#ifndef _ITEM_H_
#define _ITEM_H_

class Player;

#include <string>

class Item
{
protected:
    std::string name_;

    Item (std::string name);

public:

    virtual void giveToPlayer (Player * player) = 0;

    std::string getName (void);

    virtual std::string getDescription (void) = 0;

};

#include "Player.h"

#endif