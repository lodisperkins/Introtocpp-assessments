# The Number Guessing Game Documentation

Lodis Perkins

Matthew Williamson

s188043

Intro to C Plus Plus

## Requirements Documentation

### I.1 Description of Problem

 Problem Statement: Create a program that correctly identifies the number a user is thinking.

 Problem Specification:  User will think of a number. Once the user has thought of a number, they will tell the computer to start guessing. Computer prints a number guess to the console. After each guess, User tells the computer if the guessed number is less than, greater than, or equal to the number the User is thinking of. Program finishes when computer has guessed the correct number or the app is forced to quit. Must use variables, conditions, and loops. 

### I.2 Input Information

 The user must use the keyboard to input either a character or a string of characters.

### I.3 Output Information

 The program will display a randomly generated number on to the screen. It will also print a question asking the user to verify whether or not the number on the screen is the number they thought of.

### User Interface

![User Interface gif](https://media.giphy.com/media/5UGV3nLCiO9xMEQmCC/giphy.gif)

The user is first asked to type START!!! to begin the program. Then they are prompted to think of a number between 1 and 100. The user is then asked to validate that they have thought of a number and want to keep that number. Afterwards a series of randomly genearted numbers are printed to the console followed by questions. The user must then input y,Y,n,N,<,or > based on the input options given.

## II Design Documentation

### II.1 System Architecture Description

All of the programs functionality is in the source.cpp file.

### File Source.cpp

Name: Input(string)

Description: Stores the users input to begin the game

Name: answer(string)

Description: Stores user input used to validate that they have thought of a number

Name:Maximum(int)

Description: The maximum value the computer can generate a random number. Increases or decreases based on user input

Name: Minimum(int)

Description: The minimum value the computer can generate a random number. increases or decreases based on user input.

Name: answer(char)

Description: Stores user input of a single chracter. Used to determine whether the users number has been guessed

Name: hint(char)

Description: Stores user input and determines whether the minimum or maximum values of the random number generated increase or decrease.

Name: guess(int)

Description: Generates a random number that is used as the computers guess.

## Implementation Documentation

### File Source.cpp

```c++

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
```