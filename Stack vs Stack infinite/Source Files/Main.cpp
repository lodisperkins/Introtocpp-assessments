#include <iostream>
#include <time.h>
#include "Game.h"
#include "Hero.h"
#include "Stack.h"
#include "Game.h"
int main()
{
	//Creates a loop that allows the user to go back to the main menu after the game has finished
	while (true)
	{
		int input;
		Game civilWar;
		//Prints out available options for main menu
		std::cout << "Stack vs. Stack Infinite\n";
		std::cout << " \n";
		std::cout << "Select game mode\n";
		std::cout << "(1) Play as team Iron Man\n";
		std::cout << "(2) Play as team Captain America\n";
		std::cout << "(3) Watch the teams battle\n";


		std::cin >> input;
		system("cls");

		civilWar.mode(input);

		srand(time(NULL));

		//team 1
		Hero ironMan("Ironman");
		Hero warMachine("War Machine");
		Hero blackWidow("Black Widow");
		Hero blackPanther("Black Panther");
		Hero vision("Vision");
		Hero spiderMan("Spider Man");
		//team 2
		Hero capMerica("Captain America");
		Hero hawkeye("Hawk Eye");
		Hero falcon("Falcon");
		Hero bucky("Bucky");
		Hero scarletWitch("Scarlet Witch");
		Hero antMan("Ant-Man");;

		Hero *ptr;
		//Pushes heroes into two separate stacks
		Stack Team1("Team Iron Man");
		ptr = &ironMan;
		Team1.Push(ptr);
		ptr = &warMachine;
		Team1.Push(ptr);
		ptr = &blackWidow;
		Team1.Push(ptr);
		ptr = &blackPanther;
		Team1.Push(ptr);
		ptr = &vision;
		Team1.Push(ptr);
		ptr = &spiderMan;
		Team1.Push(ptr);

		Stack Team2("Team Captain America");
		ptr = &capMerica;
		Team2.Push(ptr);
		ptr = &hawkeye;
		Team2.Push(ptr);
		ptr = &falcon;
		Team2.Push(ptr);
		ptr = &bucky;
		Team2.Push(ptr);
		ptr = &scarletWitch;
		Team2.Push(ptr);
		ptr = &antMan;
		Team2.Push(ptr);





		//creates a loop that repeatedly calls the battle function to cycle through heroes until at least one stack is empty
		bool endGame = true;
		while (endGame)
		{
			system("cls");
			endGame = civilWar.Battle(Team1, Team2);

		}
		//Allows the user to either exit the program or start the loop again
		std::cout << " Press 'q' to quit or w to play again\n";
		std::cin >> input;
		if (input == 'q')
		{
			break;
		}
		else if (input == 'w')
		{
			continue;
		}
	}
}