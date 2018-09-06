#include <iostream>
#include <string>
int sumnumbas(int a, int b, int c)
{
	int result = 0;
	result = a + b + c;
	return result;
}
int main()
{
	char grid[3][3] = { {'a','a','a'}, {'a','a','a'}, {'a','a','a'} };
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
				if (grid[x][y] == 'a')
				{
					grid[x][y] = 'x';
					turnx = false;
					turno = true;
					break;
				}
				else if (grid[x][y] != 'a')
				{
					std::cout << "o is already there\n";
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
		bool victoryMetX = false;
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
		//o's turn. o is asked to input their desired cooridinates however if the cooridinates given is not equal to the place holder or 'a' the loop asks for a different input
		if (turno = true)
		{
			std::cout << "o's turn\n";
			for (turno; turno = true;)
			{
				std::cin >> x; std::cout << ", "; std::cin >> y;
				if (grid[x][y] == 'a')
				{
					grid[x][y] = 'o';
					turno = false;
					break;
				}
				else if (grid[x][y] != 'a')
				{
					std::cout << "x is already there\n";
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
		
		bool victoryMetO = false;
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
		if (((victoryMetX == false) && (victoryMetO == false)) && (turns >= 4))
		{
			std::cout << "Ya both lost\n";
			break;
		}
		else if (((victoryMetX == false) && (victoryMetO == false)) && (turns < 4))
		{
			turns++;			
		}
		
	} while (true);
	system("pause");
}