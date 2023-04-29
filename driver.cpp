#include "iostream"

#include "Game.h"

int main ()
{

    /*Armor * armor = new Armor ("ChestPlate" , 1);
    Weapon * weapon = new Weapon ("fists" , 2 , 1);
    Player * player_ = new Player ("Hero" , 100 , armor , weapon);

    Enemy * enemy = new Enemy ("Dog" , 20 , 0 , 2 , 1 , "A dog Jumps in frount of you" , "The dog charges and bites you" , "The dog falls to the ground");

    Event * fight0 = new Battle ("Dog Fight" , "The dog runs off. You've won the fight" , enemy);

    fight0->trigger (player_);*/

    
    Game game;

    game.build ();

    game.play ();

    return 0;
}