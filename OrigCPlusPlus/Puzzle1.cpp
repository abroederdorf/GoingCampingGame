/********************************************************************
 * Program Filename: Puzzle1.cpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Implementation for Puzzle1, derived from PuzzleRoom
 * Input: Characters for user choice and string for combination
 * Output: Print room status, objective, list of items, and if user 
 * guess is correct
 * *****************************************************************/
 
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Puzzle1.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

/****************
* Function Name: Default constructor
* Description: This function is the default constructor for Puzzle1 with
* no input parameters. It adds items to vector 
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
Puzzle1::Puzzle1():PuzzleRoom()
{ 
	//Test print
		//cout << "\nPuzzle1 Constructor: Entered";

	//Add items
	items.push_back(MAP);
	items.push_back(COMPASS);
	items.push_back(SUNGLASSES);
	items.push_back(JACKET);
}

/****************
* Function Name: Default constructor
* Description: This function is the default constructor for Puzzle1 with
* two string input parameters. It adds items to vector
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
Puzzle1::Puzzle1(string iName, string iType):PuzzleRoom(iName, iType)
{ 
	//Test print
		//cout << "\nPuzzle1 Constructor: Entered";

	//Add items
	items.push_back(MAP);
	items.push_back(COMPASS);
	items.push_back(SUNGLASSES);
	items.push_back(JACKET);
}

/****************
* Function Name: setCombination
* Description: This function takes no parameters and returns no value. It creates
* the combination and sets the value
* Parameters: None
* Pre-Conditions: Seed created for random number
* Post-Conditions: combination member data value changed
****************/
void Puzzle1::setCombination()
{
	combination = rand() % 100 + 1;
}

/****************
* Function Name: interaction
* Description: This function takes no parameters and returns no values.
* It prompts the user to interact with the room, calls the setCombination
* function and loops until the player guesses the correct combination
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: status changed to true 
****************/
void Puzzle1::interaction()
{
	char userInput;
	//Initialize cabinetOpen to false, until combination is guessed
	setCabinetOpen(false);
	
	//Prompt user for choice
	cout << "\nWould you like to open the locked cabinet?";
	cout << "\nEnter Y or N: ";
	cin.get(userInput);
	cin.clear();
	cin.ignore(1000,'\n');
	
	//Validate input
	while (toupper(userInput) != 'Y' && toupper(userInput) != 'N')
	{
		cout << "Error: Invalid input. Please enter Y or N: ";
		cin.get(userInput);
		cin.clear();
		cin.ignore(1000,'\n');
	}
	
	//If user wants to interact
	if (toupper(userInput) == 'Y')
	{
		cout << "\nThe combination is a number between 1 and 100.";
		setCombination();
		
		//Loop until player guesses correct combination
		bool userGuessStatus = false;
		string userGuessStr;
		int userGuessInt;
		
		while (!userGuessStatus)
		{
			cout << "\nPlease enter your guess (integer): ";
			getline(cin,userGuessStr);
			cin.clear();
			//cin.ignore(1000,'\n');
			
			//Validate input
			while (!intValidate(userGuessStr))
			{
				cout << "\nError: Invalid input. Please enter an integer: ";
				getline(cin,userGuessStr);
				cin.clear();
				//cin.ignore(1000,'\n');
			}
			
			//Convert string to integer
			userGuessInt = strToInt(userGuessStr);
			
			//Check if user guess is correct
			if (userGuessInt == getCombination())
			{
				cout << "Correct! You got the combination.";
				userGuessStatus = true;
			}
			else if (userGuessInt > getCombination())
				cout << "Incorrect, too high. Try again.";
			else 
				cout << "Incorrect, too low. Try again.";
		}
		
		//Set cabinetOpen to true to indicate the cabinet is now open
		setCabinetOpen(true);
		
		//Print items in cabinet
		cout << "\nThis cabinet contains the following items:";
		printItems();
	}
}

/****************
* Function Name: interactionTest
* Description: This function takes no parameters and returns no values.
* It prompts the user to interact with the room, calls the setCombination
* function and loops until the player guesses the correct combination.
* For the test part, it displays what the combination is
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: status changed to true 
****************/
void Puzzle1::interactionTest()
{
	char userInput;
	//Initialize cabinetOpen to false, until combination is guessed
	setCabinetOpen(false);
	
	//Prompt user for choice
	cout << "\nWould you like to open the locked cabinet?";
	cout << "\nEnter Y or N: ";
	cin.get(userInput);
	cin.clear();
	cin.ignore(1000,'\n');
	
	//Validate input
	while (toupper(userInput) != 'Y' && toupper(userInput) != 'N')
	{
		cout << "Error: Invalid input. Please enter Y or N: ";
		cin.get(userInput);
		cin.clear();
		cin.ignore(1000,'\n');
	}
	
	//If user wants to interact
	if (toupper(userInput) == 'Y')
	{
		cout << "\nThe combination is a number between 1 and 100.";
		setCombination();
		cout << "\nThe combination is " << getCombination();
		
		//Loop until player guesses correct combination
		bool userGuessStatus = false;
		string userGuessStr;
		int userGuessInt;
		
		while (!userGuessStatus)
		{
			cout << "\nPlease enter your guess (integer): ";
			getline(cin,userGuessStr);
			cin.clear();
			//cin.ignore(1000,'\n');
			
			//Validate input
			while (!intValidate(userGuessStr))
			{
				cout << "\nError: Invalid input. Please enter an integer: ";
				getline(cin,userGuessStr);
				cin.clear();
				//cin.ignore(1000,'\n');
			}
			
			//Convert string to integer
			userGuessInt = strToInt(userGuessStr);
			
			//Check if user guess is correct
			if (userGuessInt == getCombination())
			{
				cout << "Correct! You got the combination.";
				userGuessStatus = true;
			}
			else if (userGuessInt > getCombination())
				cout << "Incorrect, too high. Try again.";
			else 
				cout << "Incorrect, too low. Try again.";
		}
		
		//Set cabinetOpen to true to indicate the cabinet is now open
		setCabinetOpen(true);
		
		//Print items in cabinet
		cout << "\nThis cabinet contains the following items:";
		printItems();
	}
}

/*int main()
{
	
	
	cout << endl;
	return 0;
}*/


/****************
* Function Name: 
* Description: 
* Parameters: 
* Pre-Conditions: 
* Post-Conditions: 
****************/
