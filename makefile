Game: driver.o Entity.o Player.o Enemy.o Item.o Weapon.o Armor.o Event.o Battle.o Node.o ItemEvent.o Game.o
	g++ driver.o Entity.o Player.o Enemy.o Item.o Weapon.o Armor.o Event.o Battle.o Node.o ItemEvent.o Game.o -o Game

driver.o: driver.cpp
	g++ -c driver.cpp

Entity.o: Entity.cpp
	g++ -c Entity.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

Enemy.o: Enemy.cpp
	g++ -c Enemy.cpp

Item.o: Item.cpp
	g++ -c Item.cpp

Weapon.o: Weapon.cpp
	g++ -c Weapon.cpp

Armor.o: Armor.cpp
	g++ -c Armor.cpp

Event.o: Event.cpp
	g++ -c Event.cpp

Battle.o: Battle.cpp
	g++ -c Battle.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

ItemEvent.o: ItemEvent.cpp
	g++ -c ItemEvent.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

run: Game
	./Game
