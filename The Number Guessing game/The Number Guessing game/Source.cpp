#include <iostream>
#include<string>
#include <time.h>
int main()
{
	std::cout << " The Number Guessing Game\n";
	std::string input;
	//start menu
	for (input; input != "START!!!";)
	{
		std::cout << "Type 'START!!!' to begin\n";
		std::cin >> input;
		if (input == "START!!!")
		{
			std::string answer;
			std::cout << "Alright! Pick a number between 1 and 100. Say 'ok' when you've got it.\n";
			std::cin >> answer;
			for (answer; answer != "ok" || answer!="Ok";)
			{
				std::cout << "You sure you wanna keep this number? Enter 'Yes' or 'No'\n";
				std::cin >> answer;
				if (answer == "No" || answer == "no")
				{
					std::cout << "Ok, pick another number between 1 and 100. Say 'ok' when you've got it.\n";
					std::cin >> answer;
					continue;
				}
				else if(answer == "Yes" || answer == "yes")
				{
					break;
				}
				else
				{
					std::cout << "Huh? I said\n";
					continue;
				}
			}
			break;
		}
		else if (input == "start")
		{
			std::cout << "C'mon you aren't excited?\n";
			continue;
		}
		else
		{
			std::cout << "What? Dude just type 'START!!!'\n";
		}
		continue;
		
	}
	std::cout << "Ok don't tell me I've got this.\n";
	srand(time(NULL));
	//Don't use std::string use characters or integers
	//add more comments as to what each variable is doing or use more descriptive
	//variable names
	int Maximum = 100;
	int Minimum = 0;
	int guess = rand() % Maximum + Minimum;
	char answer;
	char hint;
	do {
		guess = rand() % (Maximum - Minimum + 1) + Minimum;
		std::cout << "Is it " << guess << " ?'y/n'\n";
		std::cin >> answer;
		
		if (answer == 'y' || answer == 'Y')
		{
			break;
		}
		
		else if (answer == 'n' || 'N')
		{
			std::cout << "Is it lower(<) or higher(>)? \n";
			std::cin >> hint;
			if (hint == '<')
			{
				//genearte  a random number less than the current guess but larger
				//than the lowest guess
				Maximum = guess -1;
				
			}
			else if (hint == '>')
			{
				//genearte  a random number less than the current guess but larger
				//than the lowest guess
				Minimum = guess +1;
				
			}
			continue;
		}
		
		
	} while (answer != 'y');
	std::cout << "I got it ? Awesome! Please play again!\n";
	system("pause");
	do
	{
		std::cout << "Ha! Gotcha! I'm still here! Man that was a good one. Ok bye now\n";
		system("pause");
		std::cout << "Ha! You fell for it again! Man you're gullible. Ok that's it for real this time.\n";
		system("pause");
		std::cout << " Ya know I thought you would get the joke by now....\n";
		system("pause");
		std::cout << "This is just getting sad.\n";
		system("pause");
		std::cout << "You do know there are other ways to exit a program right?\n";
		system("pause");
	} while (true);


}