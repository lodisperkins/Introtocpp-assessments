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
