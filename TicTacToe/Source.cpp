#include <iostream>
#include <string>
int main()
{
	char grid[3][3] = { {'a','a','a'}, {'a','a','a'}, {'a','a','a'} };
	//these are the coordinates that the user will input to decide where to go
	int x;
	int y;
	//this is what is used to determined who's turne it is.
	bool turnx;
	bool turno;
	//integers to iterate of array
	int i;
	int j;
	int temp;
	//this is the layout for the grid. the plan is to have the user change the output of grid in the cooridinate they want
	do
	{
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
				std::cin >> x; std::cout << ", "; std::cin >> y;
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
		for (int j = 0; j <= 3; j++)
		{  
			int i = 0;
			for (int i = 0; i <= 3; i++)
			{
				if (grid[j][i] == 'x')
				{
					continue;
				}
				else if ((grid[j][i] =='x') && (i==3)) 
				{
					std::cout << "x wins\n";
					break;
				}
				else
				{
					break;
				}
			}
		}
		
		continue;
	} while (true);
	system("pause");
}