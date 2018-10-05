#include "Game.h"
#include "Stack.h"
#include "Hero.h"
#include  <time.h>
void Game::mode(int input)
{
	//Checks which game mode the player has picked
	if(input == 1)
	{
		mplayerIron = true;
	}
	else if (input == 2)
	{
		mplayerCap = true;
	}
	else if (input == 3)
	{
		msim = true;
	}
}
Game::Game()
{
}
//Compares the values of two heroes to simulate a fight
bool Game::Battle(Stack & team1, Stack & team2)
{
	Stack winner;
	Hero hero1;
	Hero hero2;
	Hero Dead("dead");
	Hero tmp;
	Stack temp = Stack();
	bool canFight = true;
	int j;
	int h;
	int pinput;
	int cinput;
	int ranHero;
	
		//team1's turn 
	//prints to the console the amount of heroes each team has left
	std::cout << team1 << ": " << team1.report() << " heroes available          " << team2 << ": " << team2.report() << " heroes available\n";
	std::cout <<" \n";
	//checks if either team has won
	if (team1.report() == 0)
	{
		canFight = false;
		winner = team2;
		std::cout << winner << " wins!!\n";
		return canFight;
	}
	else if (team2.report() == 0)
	{
		canFight = false;
		winner = team1;
		std::cout << winner << " wins!!\n";
		return canFight;
	}
	else
	{
		hero2 = team2.Top();
	}
	hero1 = team1.Top();
	hero2 = team2.Top();

	h = 0;
	//a hero from team1 randomly selects a hero from team2 to fight. it pops the heroes it doesn't want to fight off the stack until it gets its desired hero
	//the heroes it doesn't want to fight are placed in a temporary array
	ranHero = hero1.choice(team2);
	for (j = team2.report(); j > ranHero; j--)
	{
		hero2 = team2.Top();
		Hero *ptr = &hero2;
		temp.Push(ptr);
		team2.Pop();
		h++;
	}

	hero2 = team2.Top();
	std::cout << hero1.title() << " has approached " << hero2.title() << "! \n";
	std::cout << " \n";
	//	//the two heroes then continuosly fight until at least one have died
	while (canFight)
	{
		
		std::cout << hero1.title() << "              " << hero2.title() << std::endl;
		std::cout << "HP: " << hero1.HP() << "                    " << "HP: " << hero2.HP() << std::endl;
		//if mplayerIron is true it allows the user to select the options for a hero on team ironman
		if (mplayerIron == true)
		{
			//player turn


			bool pTurn = true;
			while (pTurn == true)
			{
				std::cout << "What should " << hero1.title() << " do?\n";
				std::cout << "(1)Attack\n" << "(2)Defend\n" << "(3)View Stats\n";
				std::cin >> pinput;
				if (pinput > 3 || pinput < 1)
				{
					std::cout << hero1.title() << " hesitated! \n" << hero2.title() << " has the upperhand!\n";
					break;
				}
				switch (pinput)
				{
				case(1):
				{
					hero1.Fight(hero2);
					std::cout << hero1.title() << " attacked!\n";
					pTurn = false;
					break;
				}
				case(2):
				{
					hero1.defend();
					std::cout << hero1.title() << " raised his defense!\n";
					pTurn = false;
					break;
				}
				case(3):
				{
					system("cls");
					std::cout << hero1 << std::endl;
				}

				}
			}

			if (hero1.isAlive() == false || hero2.isAlive() == false)
			{

				break;
			}

			//coms turn
			srand(time(NULL));
			cinput = rand() % 3 + 1;
			switch (cinput)
			{
			case(1):
			{
				hero2.Fight(hero1);
				std::cout << hero2.title() << " attacked!\n";
				break;

			}
			case(2):
			{
				hero1.defend();
				std::cout << hero2.title() << " raised their defense!\n";
				break;
			}
			case(3):
			{
				hero2.Fight(hero1);
				std::cout << hero2.title() << " attacked!\n";
				break;

			}
			}
			if (hero1.isAlive() == false || hero2.isAlive() == false)
			{

				break;
			}

			else
			{
				system("pause");
				system("cls");
				continue;
			}


		}
		//if msim is true it displays the stats for each hero and options are picked randomly
		else if (msim == true)
		{
			system("cls");
			std::cout << hero1.title() << "              " << hero2.title() << std::endl;
			std::cout << "HP: " << hero1.HP() << "                    " << "HP: " << hero2.HP() << std::endl;
			hero1.Fight(hero2);
			std::cout << hero1 << std::endl;
			std::cout << hero2 << std::endl;

			if (hero1.isAlive() == false || hero2.isAlive() == false)
			{
				break;
			}
			hero2.Fight(hero1);
			system("cls");
			std::cout << hero1.title() << "              " << hero2.title() << std::endl;
			std::cout << "HP: " << hero1.HP() << "                    " << "HP: " << hero2.HP() << std::endl;
			std::cout << hero1 << std::endl;
			std::cout << hero2 << std::endl;

			if (hero1.isAlive() == false || hero2.isAlive() == false)
			{
				break;
			}
			else
			{
				system("pause");
				system("cls");
				continue;
			}
		}
		//if mplayerCap is true the computer chooses an option first and then
		//it allows the user to select the options for a hero on team cap
		else if (mplayerCap == true)
		{
			//coms turn
			srand(time(NULL));
			cinput = rand() % 3 + 1;
			switch (cinput)
			{
			case(1):
			{
				hero1.Fight(hero2);
				std::cout << hero1.title() << " attacked!\n";
				break;

			}
			case(2):
			{
				hero2.defend();
				std::cout << hero1.title() << " raised their defense!\n";
				break;
			}
			case(3):
			{
				hero1.Fight(hero2);
				std::cout << hero1.title() << " attacked!\n";
				break;

			}
			}
			
			if (hero1.isAlive() == false || hero2.isAlive() == false)
			{

				break;
			}


			//player turn


			bool pTurn = true;
			while (pTurn == true)
			{
				
				std::cout << "What should " << hero2.title() << " do?\n";
				std::cout << "(1)Attack\n" << "(2)Defend\n" << "(3)View Stats\n";
				std::cin >> pinput;
				if (pinput > 3 || pinput < 1)
				{
					std::cout << hero2.title() << " hesitated! \n" << hero1.title() << " has the upperhand!\n";
					break;
				}
				switch (pinput)
				{
				case(1):
				{
					hero2.Fight(hero1);
					std::cout << hero2.title() << " attacked!\n";
					pTurn = false;
					break;
				}
				case(2):
				{
					hero2.defend();
					std::cout << hero2.title() << " raised their defense!\n";
					pTurn = false;
					break;
				}
				case(3):
				{
					system("cls");
					std::cout << hero2 << std::endl;
				}

				}
			}

			
			if (hero1.isAlive() == false || hero2.isAlive() == false)
			{

				break;
			}

			else
			{
				system("pause");
				system("cls");
				continue;
			}


		}
	}

		//	//this set of if statements checks who has won the fight and pops them off of the stack accordingly
		if (hero1.isAlive() && (!hero2.isAlive()))
		{
			std::cout << hero2.title() << " " << "has been defeated" << std::endl;
			std::cout << hero1.title() << " " << "wins this round." << std::endl;
			system("pause");
			system("cls");
			team2.Pop();
			team1.Pop();
			Hero *ptr = &hero1;
			team1.Push(ptr);

		}
		else if (((hero2.isAlive())) && (!(hero1.isAlive())))

		{
			std::cout << hero1.title() << " " << "has been defeated" << std::endl;
			std::cout << hero2.title() << " " << "wins this round." << std::endl;
			system("pause");
			system("cls");
			team1.Pop();
			team2.Pop();
			Hero *ptr = &hero2;
			team2.Push(ptr);

		}
		else if ((!(hero1.isAlive())) && (!(hero2.isAlive())))
		{
			team1.Pop();
			team2.Pop();
			std::cout << "Both heroes have fallen this round" << std::endl;
			system("pause");
			system("cls");
		}

		//	//the remaining fighters of team2 are then pushed back on to their stack
		for (h; h >= 1; h--)
		{
			tmp = temp.Top();
			Hero *ptr = &tmp;
			team2.Push(ptr);
			temp.Pop();

		}

		//	//team2's turn
		h = 0;
		//checks if anyone has won by seeing if either stack has zero heroes in it
		if (team1.report() == 0)
		{
			canFight = false;
			winner = team2;
			std::cout << winner << " wins!!\n";
			return canFight;
		}
		else if (team2.report() == 0)
		{
			canFight = false;
			winner = team1;
			std::cout << winner << " wins!!\n";
			return canFight;
		}
		else
		{
			hero2 = team2.Top();
		}
		//	//a hero from team2 randomly selects a hero from team1 to fight. it pops the heroes it doesn't want to fight off the stack until it gets its desired hero
		//	//the heroes it doesn't want to fight are placed in a temporary array

		ranHero = hero2.choice(team1);
		for (j = team1.report(); j > ranHero; j--)
		{
			hero1 = team1.Top();
			Hero *ptr = &hero1;
			temp.Push(ptr);
			team1.Pop();
			h++;

		}

		if (team1.report() == 0)
		{
			canFight = false;
			winner = team2;
			std::cout << winner << " wins\n";
			return canFight;
		}
		else if (team2.report() == 0)
		{
			canFight = false;
			winner = team1;
			std::cout << winner << " wins\n";
			return canFight;
		}
		else
		{
			hero1 = team1.Top();
		}

		//	//the two heroes then continuosly fight until at least one have died
		std::cout << hero2.title() << " has approached " << hero1.title() << "! \n";
		std::cout << " \n";
		while (canFight)
		{
			std::cout << hero1.title() << "              " << hero2.title() << std::endl;
			std::cout << "HP: " << hero1.HP() << "                    " << "HP: " << hero2.HP() << std::endl;
			//if mplayerCap is true it allows the user to select the options for a hero on team cap
			if (mplayerCap == true)
			{
				//player turn


				bool pTurn = true;
				while (pTurn == true)
				{
					if (pinput > 3 || pinput < 1)
					{
						std::cout << hero2.title() << " hesitated! \n" << hero1.title() << " has the upperhand!\n";
						break;
					}
					std::cout << "What should " << hero2.title() << " do?\n";
					std::cout << "(1)Attack\n" << "(2)Defend\n" << "(3)View Stats\n";
					std::cin >> pinput;
					switch (pinput)
					{
					case(1):
					{
						hero2.Fight(hero1);
						std::cout << hero2.title() << " attacked!\n";
						pTurn = false;
						break;
					}
					case(2):
					{
						hero2.defend();
						std::cout << hero2.title() << " raised their defense!\n";
						pTurn = false;
						break;
					}
					case(3):
					{
						system("cls");
						std::cout << hero2 << std::endl;
					}

					}
				}

				if (hero1.isAlive() == false || hero2.isAlive() == false)
				{

					break;
				}

				//coms turn
				srand(time(NULL));
				cinput = rand() % 3 + 1;
				switch (cinput)
				{
				case(1):
				{
					hero1.Fight(hero2);
					std::cout << hero1.title() << " attacked!\n";
					break;

				}
				case(2):
				{
					hero2.defend();
					std::cout << hero1.title() << " raised their defense!\n";
					break;
				}
				case(3):
				{
					hero1.Fight(hero2);
					std::cout << hero1.title() << " attacked!\n";
					break;

				}
				}
				if (hero1.isAlive() == false || hero2.isAlive() == false)
				{

					break;
				}

				else
				{
					system("pause");
					system("cls");
					continue;
				}


			}
			//if msim is true it displays the stats for each hero and options are picked randomly
			else if (msim == true)
			{
					system("cls");
					std::cout << hero1.title() << "              " << hero2.title() << std::endl;
					std::cout << "HP: " << hero1.HP() << "                    " << "HP: " << hero2.HP() << std::endl;
					hero1.Fight(hero2);
					std::cout << hero1 << std::endl;
					std::cout << hero2 << std::endl;

					if (hero1.isAlive() == false || hero2.isAlive() == false)
					{
						break;
					}
					hero2.Fight(hero1);
					
					system("cls");
					std::cout << hero1.title() << "              " << hero2.title() << std::endl;
					std::cout << "HP: " << hero1.HP() << "                    " << "HP: " << hero2.HP() << std::endl;
					std::cout << hero1 << std::endl;
					std::cout << hero2 << std::endl;

					if (hero1.isAlive() == false || hero2.isAlive() == false)
					{
						break;
					}
					else
					{
						system("pause");
						system("cls");
						continue;
					}
			}
			//if mplayerCap is true the computer chooses an option first and then
		//it allows the user to select the options for a hero on team cap
			else if (mplayerIron == true)
			{
				//coms turn
				srand(time(NULL));
				cinput = rand() % 3 + 1;
				switch (cinput)
				{
				case(1):
				{
					hero2.Fight(hero1);
					std::cout << hero2.title() << " attacked!\n";
					break;

				}
				case(2):
				{
					hero1.defend();
					std::cout << hero2.title() << " raised their defense!\n";
					break;
				}
				case(3):
				{
					hero2.Fight(hero1);
					std::cout << hero2.title() << " attacked!\n";
					break;

				}

				}
				
				if (hero1.isAlive() == false || hero2.isAlive() == false)
				{

					break;
				}


				//player turn


				bool pTurn = true;
				while (pTurn == true)
				{
					if (pinput > 3 || pinput < 1)
					{
						std::cout << hero1.title() << " hesitated! \n" << hero2.title() << " has the upperhand!\n";
						break;
					}
					std::cout << "What should " << hero1.title() << " do?\n";
					std::cout << "(1)Attack\n" << "(2)Defend\n" << "(3)View Stats\n";
					std::cin >> pinput;
					switch (pinput)
					{
					case(1):
					{
						hero1.Fight(hero2);
						std::cout << hero1.title() << " attacked!\n";
						pTurn = false;
						break;
					}
					case(2):
					{
						hero1.defend();
						std::cout << hero1.title() << " raised their defense!\n";
						pTurn = false;
						break;
					}
					case(3):
					{
						system("cls");
						std::cout << hero1 << std::endl;
					}

					}
				}

				
				
				if (hero1.isAlive() == false || hero2.isAlive() == false)
				{

					break;
				}

				else
				{
					system("pause");
					system("cls");
					continue;
				}


			}
		}

		//	//this set of if statements check who has won the fight and pops them off of the stack accordingly

		if (hero1.isAlive() && (!hero2.isAlive()))
		{
			std::cout << hero2.title() << " " << "has been defeated" << std::endl;
			std::cout << hero1.title() << " " << "wins this round." << std::endl;
			system("pause");
			team2.Pop();
			team1.Pop();
			Hero *ptr = &hero1;
			team1.Push(ptr);

		}
		else if (((hero2.isAlive())) && (!(hero1.isAlive())))

		{
			std::cout << hero1.title() << " " << "has been defeated" << std::endl;
			std::cout << hero2.title() << " " << "wins this round." << std::endl;
			system("pause");
			team1.Pop();
			team2.Pop();
			Hero *ptr = &hero2;
			team2.Push(ptr);

		}
		else if ((!(hero1.isAlive())) && (!(hero2.isAlive())))
		{
			team1.Pop();
			team2.Pop();
			std::cout << "Both heroes have fallen this round" << std::endl;
			system("pause");
		}

		//the remaining fighters of team1 are then pushed back on to their stack
		for (h; h >= 1; h--)
		{
			tmp = temp.Top();
			Hero *ptr = &tmp;
			team1.Push(ptr);
			temp.Pop();

		}

		



	
}


