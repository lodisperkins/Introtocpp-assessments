# Battle Arena Documentation

Lodis Perkins

Matthew Williamson

s188043

Intro to C Plus Plus

## I Design Documentation

### 1.0 Description of Problem

Name: Battle Arena Game

Problem Statement:  Create a game or simulation that consists of two teams of opposing forces. 

Problem Specification: The forces must be implemented as Class objects stored within two separate Stacks. The objects must contain health values. Once the turn has finished the forces (in the Stacks) are to be sorted using a sorting algorithm that will sort the force according to the remaining health of each member. The game or simulation continues its turns until all members within a force are dead, which results in a win for the force still living.

## 1.2 Input Information

There are only three input options on the screen at any given time.

(1) - Selects first option on the screen

(2) - Selects second option on the screen

(3) - Selects third option on the screen

## 1.3 Output information

The program displays the current options available. Once a battle has begun the program displays information of the stats for each character, and also information that validates user input.

## 1.4 User interface

### Main Menu

![User Interface gif](https://media.giphy.com/media/3iBtyBfAbPVCnklzud/giphy.gif)

Allows the user to select whether they will play as (1)team Ironman, (2)team Captain America, or (3)watch a simulation of the two teams battling.

### Attack Menu

![User Interface gif](https://media.giphy.com/media/dtGCcM1hegkGgGW226/giphy.gif)

This screen occurs at the beginning of a round when a players hero randomly picks another to attack. The player then takes their turn first. The console displays the amount of heroes left in both teams, and the amount of health of the two heroes currently fighting.

Option 1: Attack

    Randomly generates a number between 10 and 25, and decrements the oppponents health by the random amount generated.
Option 2: Defend

    Adds 20 to the random number generated for defense. The heroes turn is then ended.
Option 3: View Stats

    Prints the player controlled hero's health, power, and defense to the console.

### Simulation

![User Interface gif](https://media.giphy.com/media/yxFk25UWchlLVN3cz7/giphy.gif)

A hero’s health, attack power, and defensive capability is printed to the console each
time damage is taken by either hero.
If a team member has fallen the winner and loser is printed to the console. The user may press any key to progress through the simulation.

## II Design Documentation

### 2.1 System Architecture Description

![User Interface gif](https://media.giphy.com/media/22RyxCvEyggHuTwJOB/giphy.gif)

This program is divided into three classes ( Game.h, Stack.h, and Hero.h). The hero
class defines what a hero is and gives it the ability to choose who to fight, take damage
in a fight, defend itself by reducing the damage taken by other heroes, and fight other heroes. The stack class is responsible for organizing those in
the hero class into two teams. Lastly, the game class compares the values between two
heros from each team to simulate a fight. A loop in the main function repeats this process until no more heroes are left in either stack.Players can only decide when to attack and temporarily increase the amount of defense a hero has.

### File Hero.h

Name: mHealth(int)

Description: Sets the value of a heroes health to 100

Visibility: Private

Name: mPower(int)

Description: Sets the value of a heroes power to a randomly generated number

Visibility: Private

Name: mDefense(int)

Description: Sets the value of a heroes defense to a randomly generated number

Visibility: Private

Name: name(string)

Description: Sets the value of a heroes name to whatever is assigned to it upon
intitialization

Visibility: Private

Name: Hero(string)

Arguments:N/A

Description: Allows the name of the hero to be assigned and changed

Visibility: Public

Name: title(string)

Description: Prints the name of the hero to the console.

Visibility: Public

Name: changePower(void)

Arguments:N/A

Description: Generates a random number to become the heroes power each time a
fight happens

Visibility: Public

Name: changeDefense(void)

Arguments:N/A

Description: Generates a random number to become the heroes defense each time a
fight happens

Visibility: Public

Name:isAlive(bool)

Arguments:N/A

Description: Checks to see if the current heroes health is less than or greater than zero

Visibility: Public

Name: TakeDamage(void)

Arguments:attack(int)

Description: Sums up the amount of damage the opposing hero is going to take and applies it to the hero.

Visibility: Public

Name operator == (ostream)

Arguments: const Hero&

Description:Compares two heros' names power values,and health values to determine if they are the same.

Visibility: Public

Name:defend(void)

Description: Adds 20 to the current defense value thus raising overall defense in batte.

Visibility: Public

Name:choice(int)

Arguments: Stack

Description: Has the hero who called the function randomly generate a number that will
be used to determine who he/she is fighting

Visibility: Public

Name: HP(int)

Description: Prints the hero's current amount of health to the screen.

Visibility: Public

Name: operator <<(friend)

Arguments: ostream&, const Hero

Description: Prints out all of the hero's information(defense,attack,name) to the console whenever called.

Visibility: Public

### File Stack.h

Name: *mData(Hero)

Description: Allows for new memory to be allocated so that each hero can be placed into an array

Visibility: Private

Name: mCount(Int)

Description: Counts the amount of heroes total that are on the team

Visibility: Private

Name: name(string)

Description: Gives a Stack a default name

Visibility: Private

Name: Stack(Stack)

Description: Allows for the name of the stack to be changed upon initialization.

Visibility: Public

Name: Top(Hero)

Arguments:N/A

Description: Returns the last initialized index in the stacks array.

Visibility: Public

Name: Pop(bool)

Arguments: N/A

Description: If mCount is not 0 returns true and uninitializes the last part of the stacks array.
Visibility: Public

Name: Push(bool)

Arguments: Hero*

Description: If mCount is less than 6 returns true and initializes the array at the index of mCount to the argument.

Visibility: Public

Name: report(int)

Arguments: N/A

Description: Prints out the number of remaining heroes in a stack.

Visisibility: Public

Name: operator <<

Arguments: ostream&, Stack

Description: Prints out the name of the stack to the console

### File Game.h

Name: mplayerIron(bool)

Description: Is used to determine whether or not code for when a player decides to pick team Ironman is executed.

Visibility: Private

Name: mplayerCap(bool)

Description: Is used to determine whether or not code for when a player decides to pick team Captain America is executed

Visibility: Private

Name: msim(bool)

Description: Is used to determine whether or not code for when a player decides to watch the simulation is executed

Visibility: Private

Name: Battle(bool)

Arguments: Stack&, Stack&

Description: Takes a hero from each team and simulates a battle by repeatedly calling the heros' Fight and Defend functions

Visibility: Public

Name: mode(void)

Arguments: int

Description: Sets either mplayerIron, mplayerCap, or msim to true based on the value 

### File Game.cpp

Name: winner(Stack)

Description: Used to hold the information of the team that has more than 1 hero left at the end of the loop

Name: hero1(Hero)

Description: Stores the information of a hero from the team that was initialized first

Name: hero2(Hero)

Description: Stores the information of a hero from the team that was initialized second

Name: temp(Stack)

Description: Is a temporary stack that is used to hold heroes who aren't currently being used

Name: canFight(bool)

Description: Allows the teams and heroes to fight as long as its set to true

Name: j(int)

Description: Used to hold the amount of team members left in a given team

Name: h(int)

Description: Counts how many team members have been placed into the temporary stack

Name: pinput(int)

Description: Stores the input of the player

Name: cinput(int)

Description: Stores a randomly generated number 

Name: ranhero(int)

Description: Stores a randomly generated number that is used to pick the heros opponent



## Implementation Documentation

### Hero.h

```c++
#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include "Stack.h"
class Hero
{
private:
	std::string name;
	int mHealth;
	int mPower;
	int mDefense;
public:
	void Fight(Hero&);
	Hero()
	{
	
	}
	Hero(std::string thing);
	~Hero() {}
	std::string title();
	int HP();
	void changePower();
	void changeDefense();

	bool isAlive();

	void TakeDamage(int attack);
	
	bool operator == (const Hero& other);
	

	friend std::ostream& operator<<(std::ostream& os, const Hero hero);
	
	void defend();
	

	int choice(Stack team);
};
```

### Hero.cpp

```c++
#include "Hero.h"
#include "Stack.h"
#include <time.h>
#include <string>
#include "Game.h"

void Hero::Fight(Hero&fighter)
{
	changePower();
	fighter.TakeDamage(mPower);
}

Hero::Hero(std::string thing)
{
	name = thing;
	mHealth = 100;
	mPower = rand() % 25  + 10;
	mDefense = rand() % 20 +5;
}
int Hero::HP()
{
	return mHealth;
}

std::string Hero::title()
{
	return name;
}

void Hero::changePower()
{
	mPower = rand() % 25 + 15;
}

void Hero::changeDefense()
{
	mDefense =rand() % 20 + 5;
}

bool Hero::isAlive()
{
	return mHealth > 0;	
}

void Hero::TakeDamage(int attack)
{
	int damageTaken;
	changeDefense();
	damageTaken = attack-mDefense;
	if (damageTaken < 0)
	{
		
		std::cout << name << " blocked!" << std::endl;
	}
	else
	{
		mHealth = mHealth - damageTaken;
	}
	
}

bool Hero::operator==(const Hero & other)
{
	std::cout << name;
		return mHealth == other.mHealth && mPower == other.mPower && name == other.name;
	
}

void Hero::defend()
{
	
		int protection = 20;
		mDefense = protection + mDefense;
}

int Hero::choice(Stack team)
{

	int max = team.report();
	int choice;
	choice = rand() % max + 1;
	return choice;
}

std::ostream & operator<<(std::ostream & os, const Hero hero)
{
	
		os << hero.name << "'s health is: " << hero.mHealth << std::endl << hero.name << "'s power is: " << hero.mPower
			<< std::endl << hero.name << "'s defense is: " << hero.mDefense;
		return os;
	
}
```

### Stack.h

```c++

#pragma once

#include <string>

class Hero;
class Stack
{
private:
	Hero *mData;
	int mCount;
	std::string name;
public:
	Stack();
	Stack(std::string thing);
	Hero arr(int index);
	Hero Top();
	bool Pop();
	bool Push(Hero*);
	int report();
	friend std::ostream& operator << (std::ostream& os, Stack stack);
};
```

### Stack.cpp

```c++
#include "Stack.h"
#include "Hero.h"
Stack::Stack(std::string thing)
{
	mData = new Hero[6];
	mCount = 0;
	name = thing;
}
Stack::Stack()
{
	mData = new Hero[6];
	mCount = 0;
	name = "default";
}
Hero Stack::arr(int index)
{
	return mData[index];
}

Hero Stack::Top()
{
	if(mCount > 0)
		return mData[mCount-1];
}
bool Stack::Pop()
{
	if (mCount > 0)
	{
		Hero *temp = new Hero[6];		
		for (int i = 0; i < mCount - 1; i++)
		{
			temp[i] = mData[i];
		}
		delete[] mData;
		mData = new Hero[6];
		for (int i = 0; i < 6; i++)
		{
			mData[i] = temp[i];
		}
		delete[] temp;
		mCount--;
	}
	else 
	{
		return false;
	}
	return true;
}

bool Stack::Push(Hero*hero)
{
	if (mCount < 6)
	{
		mData[mCount] = *hero;
		mCount++;
	}
	else
	{
		return false;
	}
	return true;
}



int Stack::report()
{
	return mCount;
}

std::ostream & operator<<(std::ostream& os, Stack stack)
{
	os << stack.name;
	return os;
}

```

### Game.h

```c++

#pragma once
class Stack;
class Game
{
private:

	bool mplayerIron=false;
	bool mplayerCap=false;
	bool msim=false;
public:
	Game();
	bool Battle(Stack&team1, Stack&team2);
	void mode(int input);
	
};
```

### Game.cpp

```c++
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



```

### Main.cpp

```c++

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

