/********************************************************************
 * Program Filename: ClueBoolRoom.cpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Implementation file for ClueBoolRoom derived from BoolRoom
 * Input: Char for interaction function
 * Output: Print room status, clue, and prompts
 * *****************************************************************/
 
#include <iostream>
#include <string>
#include "ClueBoolRoom.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;

/****************
* Function Name: Default constructor
* Description: This function is the default constructor for BlueBoolRoom
* with no input parameters. It sets string for clue to blank
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
ClueBoolRoom::ClueBoolRoom():BoolRoom()
{
	setClue("");
}

/****************
* Function Name: Default constructor
* Description: This function is the default constructor for ClueBoolRoom with
* string input parameters. It sets clue to blank, and name, type, statusTrue,
* statusFalse, and prompt to the input values
* Parameters: 
*	string iName is the specified name of the room object
*	string iType is the specified type of the room object
*	string iStatT is the specified string for a true status
* 	string iStatF is the specified string for a false status
*	string iPrompt is the specified string to prompt the user
* Pre-Conditions: 
* Post-Conditions: 
****************/
ClueBoolRoom::ClueBoolRoom(string iName, string iType, string iStatT,
	string iStatF, string iPrompt):BoolRoom(iName, iType, iStatT, 
	iStatF, iPrompt)
{
	setClue("");
}

/****************
* Function Name: interaction
* Description: This function takes no parameters and returns no values.
* It prompts the user to interact with the room, changes the status, prints
* the new status, and displays a clue
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: Status changed to true
****************/
void ClueBoolRoom::interaction()
{
	char userInput;
	
	//Prompt user for choice
	cout << "\n" << getPrompt();
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
	
	//If user wants to interact, set status to true and print new room status
	if (toupper(userInput) == 'Y')
	{
		setStatus(true);
		printStatus();
		
		//If status is true, print clue
		if (getStatus())
			cout << "\nCLUE: " << getClue();
	}	
}

/****************
* Function Name: setClue
* Description: This function takes a string parameter and returns no value.
* The string parameter is the clue to display.
* Parameters: string iClue is the string statement for the clue
* Pre-Conditions: None
* Post-Conditions: None
****************/
void ClueBoolRoom::setClue(string iClue)
{
	clue = iClue;
}

/****************
* Function Name: getClue
* Description: This function takes no parameter and returns a string for
* the clue statement
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
string ClueBoolRoom::getClue()
{
	return clue;
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

