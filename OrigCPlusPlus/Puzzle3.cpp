/*******************************************************************
 * Program Filename: Puzzle3.cpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Implementation for Puzzle3, derived from PuzzleRoom
 * Input: Characters for user choice and string for combination
 * Output: Print room status, objective, list of items, and if user 
 * guess is correct
 *****************************************************************/
 
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <numeric>
#include "Puzzle3.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::accumulate;

/****************
* Function Name: Default constructor
* Description: This function is the default constructor for Puzzle3 with
* no input parameters. It adds items to vector and 
* initializes combTotal to 0
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
Puzzle3::Puzzle3():PuzzleRoom()
{ 
	//Add items
	items.push_back(MATCHES);
	items.push_back(KNIFE);
	items.push_back(SNICKERSBAR);
	
	//Initialize combTotal
	combTotal = 0;
}

/****************
* Function Name: Default constructor
* Description: This function is the default constructor for Puzzle3 with
* two string input parameters. It adds items to vector and 
* initializes combTotal to 0
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
Puzzle3::Puzzle3(string iName, string iType):PuzzleRoom(iName, iType)
{ 
	//Test print
		//cout << "\nPuzzle3 Constructor: Entered";

	//Add items
	items.push_back(MATCHES);
	items.push_back(KNIFE);
	items.push_back(SNICKERSBAR);
	
	//Initialize combTotal
	combTotal = 0;
}

/****************
* Function Name: setCombination
* Description: This function takes no parameters and returns no value. It creates
* the combination and sets the value
* Parameters: None
* Pre-Conditions: Seed created for rand()
* Post-Conditions: combination member data value changed
****************/
void Puzzle3::setCombination()
{
	//Create vector of 3 random odd integers
	vector <int> combDigits;
	int randNum;
	for (int i = 0; i < 3; i++)
	{
		randNum = rand() % 4 + 0;
		combDigits.push_back(2 * randNum + 1);
	}
	
	//Get total of three digits
	combTotal = accumulate(combDigits.begin(), combDigits.end(),0);
	
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
void Puzzle3::interaction()
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
		setCombination();
		cout << "\nThe combination is a random order of three odd integers between 1 and 9";
		cout << "\nIf you sum all three digits, the total is " << combTotal;
		cout << "\nExample: If the combination is 111, the sum is 3.";
				
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
void Puzzle3::interactionTest()
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
		setCombination();
		cout << "\nThe combination is a random order of three odd integers between 1 and 9";
		cout << "\nIf you sum all three digits, the total is " << combTotal;
		cout << "\nExample: If the combination is 111, the sum is 3.";
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