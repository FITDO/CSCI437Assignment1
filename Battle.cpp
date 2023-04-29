#include "Battle.h"

Battle::Battle (std::string name , std::string finishedMission , Enemy * enemy)
: Event (name , finishedMission) ,
    enemy_ (enemy)
{

}

bool Battle::happen (Player * player_)
{

    int chance = 0;
    int option = 0;

    std::cout << enemy_->getStartMessage () << std::endl;

    while (player_->getHealth() > 0 && enemy_->getHealth() > 0)
    {
        std::cout << player_->getName () << ": " << player_->getHealth () << "/" << player_->getMaxHealth () << std::endl;
        std::cout << enemy_->getName () << ": " << enemy_->getHealth () << "/" << enemy_->getMaxHealth () << std::endl;
        std::cout << enemy_->getName () << " stands before you. What will you do \n0)Run Away \n1)Attack" << std::endl;
        std::cin >> option;

        if (option == 0)
        {
            std::cout << player_->getName () << " choose to run away." << std::endl;
            return false;
        }
        else if (option == 1)
        {
            enemy_->takeDamage (player_->attack ());
            player_->takeDamage (enemy_->attack ());
        }
        else
        {
            std::cout << "You just stand there." << std::endl;
            chance = rand() % 4;
            if (chance == 3)
            {
                std::cout << enemy_->getName () << " choose to attack!" << std::endl;
                player_->takeDamage (enemy_->attack ());
            }
        }
    }

    // Heal Player

    if (player_->getHealth() < 0 && enemy_->getHealth() < 0)
    {
        std::cout << "Looks like you both fainted \nEveryone agrees to a strategic retreat" << std::endl;
        return true;
    }
    else if (enemy_->getHealth () < 0)
    {
        std::cout << enemy_->getDeathMessage() << std::endl;
        return false;
    }
    else
    {
        std::cout << player_->getName() << " limps away" << std::endl;
        return true;
    }


}