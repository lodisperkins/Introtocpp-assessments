# Tic - Tac- Toe Documentation


Lodis Perkins

Matthew Williamson

s188043

Intro to C Plus Plus

## Requirements Documentation

### I.1 Description of Problem

 Problem Statement: Create a program that allows two players on the same computer to play a game of Tic Tac Toe

Problem Specification: Two players alternate placing tokens on a 3 by 3 grid. The first player to get three of their respective tokens in a row wins. Player cannot place tokens on occupied sections of the grid. A player cannot place more than one token on their turn. A victory condition is met when a player has placed three of their tokens in a row horizontally, vertically, or diagonally. If all sections of the grid are filled and no player has met a victory condition the game ends in a draw. Program will finish when app is forced to quit, a player has won, or the draw condition is met. Must use variables, conditionals, loops, and arrays.

### I.2 Input Information

 The user must use the key board to input numbers determining where they would like to go.

### I.3 Output Information

 The program will display a three by three grid that updates each time a piece is placed

### User Interface

![User Interface gif](https://media.giphy.com/media/2dc66BQwAwZ6K2L5ye/giphy.gif)

The user is first asked to press any key to begin the game. Afterwards a grid is displayed on screen. The user must then type a number between 0 and 2 twice to set a coordinate that they would like to put their piece in.

## II Design Documentation

### II.1 System Architecture Description

All of the programs functionality is in the source.cpp file.

### File Source.cpp

Name: grid[][](char)

Description:The array that the pieces will be placed in.

Name: x(int)

Description: Stores user input for the x cooridinate

Name:y(int)

Description: Stores user input for the y cooridinate

Name:turnx(bool)

Description: Is used to determine whether or not the player placing the x token is allowed to place tokens

Name: turno(bool)

Description: Is used to determine whether or not the player placing the o token is allowed to place tokens

Name: turns(int)

Description: Counts the amount of possible turns left in the game is used to check when the game is over and ended in a draw.

Name: victoryMetO(bool)

Description: Checks if the user placing the o token has won the game

Name: victoryMetX(bool)

Description: Checks if the user placing the x token has won the game

## Implementation Documentation

### File Source.cpp

```c++

#include <iostream>
#include <string>

int main()
{
	std::cout << "Good ole fashioned Tic-Tac-Toe. Input the the cooridinate of the spot you would like to choose to be the first to have\n";
	std::cout << " three in a row\n";
	system("pause");
	char grid[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
	//these are the coordinates that the user will input to decide where to go
	int x;
	int y;
	//this is what is used to determined who's turn it is.
	bool turnx;
	bool turno;
	//integers to iterate of array
	int turns = 0;
	bool victoryMetO = false;
	bool victoryMetX = false;
	//this is the layout for the grid. the plan is to have the user change the output of grid in the cooridinate they want
	do
	{
		system("cls");
		std::cout << "     0        1         2\n";
		std::cout << "        " << grid[0][0] << "|       " << grid[0][1] << "|   " << grid[0][2] << std::endl;
		std::cout << "0" << "   _____|________|_____\n";
		std::cout << "        " << grid[1][0] << "|       " << grid[1][1] << "|   " << grid[1][2] << std::endl;
		std::cout << "1" << "   _____|________|_____\n";
		std::cout << "2" << "        |        |        \n";
		std::cout << "        " << grid[2][0] << "|       " << grid[2][1] << "|   " << grid[2][2] << std::endl;
		//x's turn. x is asked to input their desired cooridinates however if the coordinates given is not equal to the place holder or 'a' the loop asks for a different input
		turnx = true;
		if (turnx = true)
		{
			std::cout << "x's turn\n";
			for (turnx; turnx = true;)
			{
				std::cout << "Enter a coordinate ";
				std::cin >> x >> y;
				if (grid[x][y] == ' ')
				{
					grid[x][y] = 'x';
					turnx = false;
					turno = true;
					break;
				}
				else if (grid[x][y] != ' ')
				{
					std::cout << "Looks like you can't go  there\n";
					continue;
				}
			}
		}
		system("cls");
		std::cout << "     0        1         2\n";
		std::cout << "        " << grid[0][0] << "|       " << grid[0][1] << "|   " << grid[0][2] << std::endl;
		std::cout << "0" << "   _____|________|_____\n";
		std::cout << "        " << grid[1][0] << "|       " << grid[1][1] << "|   " << grid[1][2] << std::endl;
		std::cout << "1" << "   _____|________|_____\n";
		std::cout << "2" << "        |        |        \n";
		std::cout << "        " << grid[2][0] << "|       " << grid[2][1] << "|   " << grid[2][2] << std::endl;
		//the winning conditions for x are checked if the boolean victroyMetX is true the loop breaks
		
		if (((grid[0][0] == 'x') && (grid[0][1] == 'x')) && (grid[0][2] == 'x'))
		{
			victoryMetX = true;
		}
		else if (((grid[1][0] == 'x') && (grid[1][1] == 'x')) && (grid[1][2] == 'x'))
		{
			victoryMetX = true;
		}
		else if (((grid[2][0] == 'x') && (grid[2][1] == 'x')) && (grid[2][2] == 'x'))
		{
			victoryMetX = true;
		}
		else if (((grid[0][0] == 'x') && (grid[1][0] == 'x')) && (grid[2][0] == 'x'))
		{
			victoryMetX = true;
		}
		else if (((grid[0][1] == 'x') && (grid[1][1] == 'x')) && (grid[2][1] == 'x'))
		{
			victoryMetX = true;
		}
		else if (((grid[0][2] == 'x') && (grid[0][2] == 'x')) && (grid[2][2] == 'x'))
		{
			victoryMetX = true;
		}
		else if (((grid[0][0] == 'x') && (grid[1][1] == 'x')) && (grid[2][2] == 'x'))
		{
			victoryMetX = true;
		}
		else if (((grid[2][0] == 'x') && (grid[1][1] == 'x')) && (grid[0][2] == 'x'))
		{
			victoryMetX = true;
		}

		if (victoryMetX == true)
		{
			std::cout << " x wins!" << std::endl;
			break;
		}
		//this checks for a tie
		if (((victoryMetX == false) && (victoryMetO == false)) && (turns >= 4))
		{
			std::cout << "Ya both lost\n";
			break;
		}
		//o's turn. o is asked to input their desired cooridinates however if the cooridinates given is not equal to the place holder or 'a' the loop asks for a different input
		if (turno = true)
		{
			std::cout << "o's turn\n";
			for (turno; turno = true;)
			{
				std::cin >> x >> y;
				if (grid[x][y] == ' ')
				{
					grid[x][y] = 'o';
					turno = false;
					break;
				}
				else if (grid[x][y] != ' ')
				{
					std::cout << "Looks like you can't go there\n";
					continue;
				}
			}
		}
		system("cls");
		std::cout << "     0        1         2\n";
		std::cout << "        " << grid[0][0] << "|       " << grid[0][1] << "|   " << grid[0][2] << std::endl;
		std::cout << "0" << "   _____|________|_____\n";
		std::cout << "        " << grid[1][0] << "|       " << grid[1][1] << "|   " << grid[1][2] << std::endl;
		std::cout << "1" << "   _____|________|_____\n";
		std::cout << "2" << "        |        |        \n";
		std::cout << "        " << grid[2][0] << "|       " << grid[2][1] << "|   " << grid[2][2] << std::endl;
		//the winning conditions for o are checked if the boolean victroyMetO is true the loop breaks
		
		if (((grid[0][0] == 'o') && (grid[0][1] == 'o')) && (grid[0][2] == 'o'))
		{
			victoryMetO = true;
		}
		else if (((grid[1][0] == 'o') && (grid[1][1] == 'o')) && (grid[1][2] == 'o'))
		{
			victoryMetO = true;
		}
		else if (((grid[2][0] == 'o') && (grid[2][1] == 'o')) && (grid[2][2] == 'o'))
		{
			victoryMetO = true;
		}
		else if (((grid[0][0] == 'o') && (grid[1][0] == 'o')) && (grid[2][0] == 'o'))
		{
			victoryMetO = true;
		}
		else if (((grid[0][1] == 'o') && (grid[1][1] == 'o')) && (grid[2][1] == 'o'))
		{
			victoryMetO = true;
		}
		else if (((grid[0][2] == 'o') && (grid[0][2] == 'o')) && (grid[2][2] == 'o'))
		{
			victoryMetO = true;
		}
		else if (((grid[0][0] == 'o') && (grid[1][1] == 'o')) && (grid[2][2] == 'o'))
		{
			victoryMetO = true;
		}
		else if (((grid[2][0] == 'o') && (grid[1][1] == 'o')) && (grid[0][2] == 'o'))
		{
			victoryMetO = true;
		}

		if (victoryMetO == true)
		{
			std::cout << " o wins!" << std::endl;
			break;
		}
		else
		{
			victoryMetO = false;
		}
		//if neither are set to true and the game still has turns left the loop continues
		if (((victoryMetX == false) && (victoryMetO == false)) && (turns < 4))
		{
			turns++;			
		}
		
	} while (true);
	system("pause");
}
```