#ifndef _NODE_H_
#define _NODE_H_

#include <string>

#include "Player.h"
#include "Battle.h"

class Node
{
protected:

    std::string name_;
    std::string description_;

    Node * north_;
    Node * east_;
    Node * south_;
    Node * west_;

    Event * event_;
    bool hasEvent_;
    bool triggerEventOnStart_;
    bool kickOutOfRoomOnEventFail_;

public:

    Node (std::string name , std::string description);

    std::string getName (void);

    std::string getDescription (void);

    void setNorth (Node * node);

    Node * getNorth (void);

    void setEast (Node * node);

    Node * getEast (void);

    void setSouth (Node * node);

    Node * getSouth (void);

    void setWest (Node * node);

    Node * getWest (void);

    void setEvent (Event * event , bool triggerOnEnter , bool KickOutOfRoom);

    bool startEvent (Player * player);

    bool getHasEvent (void);

    bool getTriggerOnStart (void);

    bool getKickOutOfRoomOnFail (void);

};

#endif