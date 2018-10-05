#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	int rnum = rand() % 10 +1;
	int guess;
	do {
		cout << "Guess number\n";
		cin >> guess;
		if (rnum < guess)
		{
			cout << "Its lower\n";
		}
		else if (rnum > guess)
		{
			cout << "Its Higher\n";
		}
	} while (rnum != guess);
	cout << "Nice\n";

		
	
	
	system("pause");
}