#include "Game.h"

Game::Game (void)
: player_ (nullptr) ,
    nodePTR_ (nullptr)
{

}

void Game::build (void)
{

    Armor * armor = new Armor ("ChestPlate" , 1);
    Weapon * weapon = new Weapon ("fists" , 2 , 1);
    player_ = new Player ("Hero" , 100 , armor , weapon);

    Node * start = new Node ("Start" , "The adventure has begun");
    Node * node0 = new Node ("Open Field" , "An empty field. It seems to go on for quite some time. However, you see some smoke to the east");
    Node * node1 = new Node ("Campfire" , "There is a almost unlit campfire. It looks like its been some time since someone has been here. You see some footprints to the North");
    Node * node2 = new Node ("Field" , "You Step into an open field There is nothing here.");
    Node * node3 = new Node ("Battlesite" , "You step into a battlesite everything has been destroyied however it may be worth looking around");

    Enemy * enemy = new Enemy ("Dog" , 20 , 0 , 2 , 1 , "A dog Jumps in frount of you" , "The dog charges and bites you" , "The dog falls to the ground");
    Item * dagger = new Weapon ("Dagger" , 3 , 2);

    Event * fight0 = new Battle ("Dog Fight" , "The dog runs off. You've won the fight" , enemy);
    Event * itemEvent0 = new ItemEvent ("Get dagger" , "A skeleton hold a dagger?" , dagger , "With some resistence you manage to take the dagger out of the skeletons hands.");
    
    start->setNorth (node0);
    node0->setSouth (start);
    node0->setEast (node1);
    node1->setWest (node0);
    node1->setNorth (node2);
    node2->setSouth (node1);
    node2->setEvent (fight0 , true , true);
    node2->setNorth (node3);
    node3->setSouth (node2);
    node3->setEvent (itemEvent0 , false , false);

    this->nodePTR_ = start;

}

void Game::play (void)
{
    if (nodePTR_)
    {
        this->takeInput ();
    }
    else
    {
        std::cout << "Game has not been build" << std::endl;
    }
}

void Game::takeInput (void)
{
    int userInput = 0;
    bool keepPlaying = true;
    while (keepPlaying)
    {
        std::cout << nodePTR_->getName () << ":\n" << nodePTR_->getDescription () << std::endl;
        std::cin.clear ();

        if (!nodePTR_->getTriggerOnStart ())
        {

            userInput = this->makeRoomMenu ();


            if (userInput == 0)
            {
                std::cout << "Test" << std::endl;
            }
            else if (userInput == 1 && nodePTR_->getNorth ())
            {
                this->previousNode_ = this->nodePTR_;
                this->nodePTR_ = this->nodePTR_->getNorth ();
            }
            else if (userInput == 2 && nodePTR_->getEast ())
            {
                this->previousNode_ = this->nodePTR_;
                this->nodePTR_ = this->nodePTR_->getEast ();
            }
            else if (userInput == 3 && nodePTR_->getSouth ())
            {
                this->previousNode_ = this->nodePTR_;
                this->nodePTR_ = this->nodePTR_->getSouth ();
            }
            else if (userInput == 4 && nodePTR_->getWest ())
            {
                this->previousNode_ = this->nodePTR_;
                this->nodePTR_ = this->nodePTR_->getWest();
            }
            else if (userInput == 5 && this->nodePTR_->getHasEvent ())
            {
                std::cout << "Hello World" << std::endl;
                this->nodePTR_->startEvent (player_);
            }
            
            else if (userInput == 9)
            {
                std::cout << "Are you sure you want to quit? \n0)No \n1)Yes" << std::endl;
                std::cin >> userInput;

                if (userInput == 1)
                {
                    keepPlaying = false;
                }
            }
            else
            {
                std::cout << "You just stand there" << std::endl;
                std::cin.ignore ();
            }
        }
        else // There is an event
        {
            if (this->nodePTR_->getKickOutOfRoomOnFail ())
            {
                if (this->nodePTR_->startEvent (player_))
                {
                    // Event was Finished
                }
                else // Event Failed
                {
                    this->nodePTR_ = this->previousNode_;
                }
            }
            else
            {
                this->nodePTR_->startEvent (player_);
            }
        }
    }

    std::cout << "Game Ending" << std::endl;
}

int Game::makeRoomMenu (void)
{
    int input = 8;
    std::string menu = "0) Check Equipment\n";
    if (nodePTR_->getNorth ())
    {
        menu += "1) Head North\n";
    }

    if (nodePTR_->getEast ())
    {
        menu += "2) Head East\n";
    }

    if (nodePTR_->getSouth ())
    {
        menu += "3) Head South\n";
    }

    if (nodePTR_->getWest ())
    {
        menu += "4) Head West\n";
    }

    if (nodePTR_->getHasEvent ())
    {
        menu += "5) Somethings Here\n";
    }

    menu += "9) QUIT\n";

    std::cout << menu;
    std::cin >> input;
    return input;
}