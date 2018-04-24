#include "Game.h"

int main()
{
	bool gameOver = false;
	//create game object
	Game game;
	//gets character name
	game.setGame();
	//prints the intro
	game.printIntro();
	//game.printHelp();
	//gameplay loop
	while (!gameOver)
	{
		game.gameMenu();
		//game.printEvent();
	}
	return 0;
}