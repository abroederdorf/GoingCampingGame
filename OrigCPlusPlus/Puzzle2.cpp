/********************************************************************
 * Program Filename: Puzzle2.cpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Implementation for Puzzle2, derived from PuzzleRoom
 * Input: Characters for user choice and string for combination
 * Output: Print room status, objective, list of items, and if user 
 * guess is correct
 * *****************************************************************/
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Puzzle2.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::random_shuffle;

/****************
* Function Name: Default constructor
* Description: This function is the default constructor for Puzzle2 with
* no input parameters. It adds items to vector 
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
Puzzle2::Puzzle2():PuzzleRoom()
{ 
	//Add items
	items.push_back(HEADLAMP);
	items.push_back(FIRSTAID);
	items.push_back(FIRESTARTER);
}

/****************
* Function Name: Default constructor
* Description: This function is the default constructor for Puzzle2 with
* two string input parameters. It adds items to vector
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
Puzzle2::Puzzle2(string iName, string iType):PuzzleRoom(iName, iType)
{ 
	//Test print
		//cout << "\nPuzzle2 Constructor: Entered";

	//Add items
	items.push_back(HEADLAMP);
	items.push_back(FIRSTAID);
	items.push_back(FIRESTARTER);
}

/****************
* Function Name: setCombination
* Description: This function takes no parameters and returns no value. It creates
* the combination and sets the value
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: combination member data value changed
****************/
void Puzzle2::setCombination()
{
	//Create vector of 1, 2, 3
	vector <int> combDigits;
	combDigits.push_back(1);
	combDigits.push_back(2);
	combDigits.push_back(3);
	
	//Shuffle digits in vector
	random_shuffle(combDigits.begin(),combDigits.end());
	
	//Create combination value from digits in vector
	combination = combDigits[0] * 100 + combDigits[1] * 10 + combDigits[2];
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
void Puzzle2::interaction()
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
		cout << "\nThe combination is a random order of the digits 1, 2, and 3";
		cout << "\nExample: The combination might be 123 or 321";
		setCombination();
		
		//Loop until player guesses correct combination
		bool userGuessStatus = false;
		string userGuessStr;
		int userGuessInt;
		
		while (!userGuessStatus)
		{
			cout << "\nPlease enter your guess (3 digit integer): ";
			getline(cin,userGuessStr);
			cin.clear();
			//cin.ignore(1000,'\n');
			
			//Validate input
			while (!intValidate(userGuessStr))
			{
				cout << "\nError: Invalid input. Please enter a 3 digit integer: ";
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
			else
				cout << "Incorrect, try again.";
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
* function and loops until the player guesses the correct combination
* For the test part, it displays what the combination is
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: status changed to true 
****************/
void Puzzle2::interactionTest()
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
		cout << "\nThe combination is a random order of the digits 1, 2, and 3";
		cout << "\nExample: The combination might be 123 or 321";
		setCombination();
		cout << "\nThe combination is " << getCombination();
		
		//Loop until player guesses correct combination
		bool userGuessStatus = false;
		string userGuessStr;
		int userGuessInt;
		
		while (!userGuessStatus)
		{
			cout << "\nPlease enter your guess (3 digit integer): ";
			getline(cin,userGuessStr);
			cin.clear();
			//cin.ignore(1000,'\n');
			
			//Validate input
			while (!intValidate(userGuessStr))
			{
				cout << "\nError: Invalid input. Please enter a 3 digit integer: ";
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
			else
				cout << "Incorrect, try again.";
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