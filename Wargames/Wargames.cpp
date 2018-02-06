// Wargames.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Wargames
//The Multi-Algorithm Searching Simulation

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int LinearAI(int _target)
{
	int tries = 0;
	int target = _target;
	int prediction; 

	do
	{
		tries++;
		cout << "Scanning..." << endl;
		//get prediction
		prediction = tries; 

		//test prediction
		if (prediction != target)
		{
			cout << "Not Found." << endl;
		}

	} while (prediction != target);

	cout << "Target Found." << endl;
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
		cout << "Scanning..." << endl;
		//get prediction
		prediction = ((highParameter - lowParameter) / 2) + lowParameter; 

		//test prediction
		if (prediction < target)	//if prediction too low
		{
			//adjust lowParameter
			lowParameter = prediction + 1;
		}
		else if (prediction > target)	// if prediction too high
		{
			//adjust highParameter
			highParameter = prediction - 1; 
		}
	} while (prediction != target);

	cout << "Target Found." << endl;
	return tries;
}

int RandomAI(int _target)
{
	int tries = 0;
	int target = _target;
	int prediction;

	cout << "Please Wait..." << endl;
	do
	{
		tries++;
		//cout << "Scanning..." << endl;
		//get prediction
		srand(static_cast<unsigned int>(time(0)));		//seed random number generator
		prediction = rand() % 64 + 1;		//random number between 1 and 64; 

		/*
		//test prediction
		if (prediction != target)
		{
			cout << "Not Found." << endl;
		}
		*/

	} while (prediction != target);

	cout << "Target Found." << endl;
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
		if (prediction < target)
		{
			cout << "Prediction too low." << endl;
		}
		else if (prediction > target)
		{
			cout << "Prediction too high." << endl;
		}

	} while (prediction != target);

	cout << "Target Found." << endl;
	return tries;
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));		//seed random number generator

	int targetLocation = rand() % 64 + 1;		//random number between 1 and 64; 
	int linearTries, binaryTries, randomTries, humanTries = 0;

	cout << "\tBeginning Wargames Simulation.\n\n";

	//run each test in sequence
	cout << "Running Human Test." << endl;
	humanTries = Human(targetLocation);
	cout << "Running Linear AI Test." << endl;
	linearTries = LinearAI(targetLocation);
	cout << "Running Binary AI Test." << endl;
	binaryTries = BinaryAI(targetLocation);
	cout << "Running Random AI Test." << endl;
	randomTries = RandomAI(targetLocation);
	cout << "All Tests Complete." << endl << endl;

	//display results
	cout << "\tResults: \n";
	cout << "The Human found the target in " << humanTries << " guesses." << endl;
	cout << "The Linear AI found the target in " << linearTries << " guesses." << endl;
	cout << "The Binary AI found the target in " << binaryTries << " guesses." << endl;
	cout << "The Random AI found the target in " << randomTries << " guesses." << endl;

	/*
	//determine winner
	if (humanTries < linearTries && humanTries < binaryTries && humanTries < randomTries)	//if humanTries is lowest
	{
		cout << "The Human Wins! \n\n"; 
	}
	else if (linearTries < humanTries && linearTries < binaryTries && linearTries < randomTries)	//if linearTries is lowest
	{
		cout << "The Linear AI Wins! \n\n";
	}
	else if (binaryTries < humanTries && binaryTries < linearTries && binaryTries < randomTries)	//if binaryTries is lowest
	{
		cout << "The Binary AI Wins! \n\n";
	}
	else if (randomTries < humanTries && randomTries < linearTries && randomTries < binaryTries)	//if randomTries is lowest
	{
		cout << "The Random AI Wins! \n\n";
	}
	*/

	//end program
	cout << "\tEnding Simulation.\n\n";
	system("pause");
	return 0;
}
