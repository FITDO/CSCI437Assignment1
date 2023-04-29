#include "Event.h"

Event::Event (std::string name , std::string finishedMessage)
: canHappen_ (true) ,
    name_ (name) ,
    finishedMessage_ (finishedMessage)
{

}

std::string Event::getName (void)
{
    return this->name_;
}

bool Event::getHasHappened (void)
{
    return this->canHappen_;
}

bool Event::trigger (Player * player)
{
    std::cout << "Hello" << std::endl;
    if (this->canHappen_)
    {
        bool eventFinished = this->happen (player);
        this->canHappen_ = !eventFinished;
        return eventFinished;
    }
    else
    {
        std::cout << "Its already happened" << std::endl;
        // The event has already happened so nothing happens
        return true;
    }
}