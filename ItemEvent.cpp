#include "ItemEvent.h"

ItemEvent::ItemEvent (std::string name , std::string description , Item * item , std::string finalMessage)
: Event (name , finalMessage) ,
    item_ (item) ,
    description_ (description)
{

}

bool ItemEvent::happen (Player * player)
{
    int choice = 2;
    std::cout << "Hello" << std::endl;
    while (true)
    {
        std::cout << description_ << std::endl;
        std::cout << "Do you take it? \n0)No \n1)Yes" << std::endl;
        std::cin >> choice;
    
        if (choice == 0)
        {
            std::cout << "You decide to leave the " << this->item_->getName () << std::endl;
            return false;
        }
        else if (choice == 1)
        {
            this->item_->giveToPlayer (player);
            std::cout << this->finishedMessage_ << std::endl;
            return true;
        }
    }
}