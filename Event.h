#ifndef _EVENT_H_
#define _EVENT_H_

#include "Player.h"

class Event
{
protected:

    std::string name_;
    std::string finishedMessage_;
    bool canHappen_;

    Event (std::string name , std::string finishedMessage);

public:

    std::string getName (void);

    bool getHasHappened (void);

    bool trigger (Player * player);

    virtual bool happen (Player * player) = 0;
};

#endif