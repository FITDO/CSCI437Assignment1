#ifndef _GAME_H_
#define _GAME_H_

#include "ItemEvent.h"
#include "Battle.h"
#include "Node.h"

class Game
{
private:

    Player * player_;
    Node * nodePTR_;
    Node * previousNode_;

    void takeInput (void);

    int makeRoomMenu (void);

public:

    Game (void);

    void build (void);

    void play (void);

};

#endif