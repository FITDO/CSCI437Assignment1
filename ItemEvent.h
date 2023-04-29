#ifndef _ITEMEVENT_H_
#define _ITEMEVENT_H_

#include "Event.h"
#include "Item.h"

class ItemEvent : public Event
{
protected:

    std::string description_;
    Item * item_;

public:

    ItemEvent (std::string name , std::string description , Item * item , std::string finalMessage);

    bool happen (Player * player);

};

#endif