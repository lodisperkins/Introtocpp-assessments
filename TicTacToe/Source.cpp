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
	int i;
	int j;
	int temp;
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