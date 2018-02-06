// Wargames.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Wargames
//The Multi-Algorithm Searching Simulation

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
	srand(static_cast<unsigned int>(time(0)));		//seed random number generator

	int targetLocation = rand() % 64 + 1;		//random number between 1 and 64; 
	int LinearTries, BinaryTries, RandomTries, HumanTries = 0;

	cout << "\tBeginning Wargames Simulation.\n\n";

	HumanTries = Human(targetLocation);
	LinearTries = LinearAI(targetLocation);
	BinaryTries = BinaryAI(targetLocation);
	RandomTries = RandomAI(targetLocation);
	
	/*
	do
	{
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;

		if (guess > targetLocation)
		{
			cout << "Too high!\n\n";
		}
		else if (guess < targetLocation)
		{
			cout << "Too low!\n\n";
		}
		else
		{
			cout << "\nThat's it!  You got it in " << tries << " guesses!\n";
		}
	} while (guess != targetLocation);
	*/

	cout << "\tEnding Simulation.\n\n";
	system("pause");
	return 0;
}

int LinearAI(int _target)
{
	int tries = 0;
	int target = _target;
	int prediction; 

	do
	{
		tries++;
		//get prediction
		prediction = tries; 

		//test prediction

	} while (prediction != target);

	return tries;
}

int BinaryAI(int _target)
{
	int tries = 0;
	int target = _target;
	int prediction;
	int highParameter = 64; 
	int lowParameter = 1; 

	do
	{
		tries++;
		//get prediction
		int prediction = ((highParameter - lowParameter) / 2) + lowParameter; 

		//test prediction

	} while (prediction != target);

	return tries;
}
int RandomAI(int _target)
{
	int tries = 0;
	int target = _target;
	int prediction;

	do
	{
		tries++;
		//get prediction
		srand(static_cast<unsigned int>(time(0)));		//seed random number generator
		prediction = rand() % 64 + 1;		//random number between 1 and 64; 

		//test prediction


	} while (prediction != target);

	return tries;
}
int Human(int _target)
{
	int tries = 0;
	int target = _target;
	int prediction;

	do
	{
		tries++;
		//get prediction
		cout << "Guess a number (1-64): " << endl;
		cin >> prediction; 

		//test prediction

	} while (prediction != target);

	return tries;
}
