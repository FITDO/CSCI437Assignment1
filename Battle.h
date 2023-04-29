#ifndef _BATTLE_H_
#define _BATTLE_H_

#include "Event.h"

#include "Player.h"
#include "Enemy.h"

class Battle : public Event
{
protected:

    Player * player_;
    Enemy * enemy_;

public:

    Battle (std::string name , std::string finishedMission , Enemy * enemy);

    bool happen (Player * player);

};

#endif