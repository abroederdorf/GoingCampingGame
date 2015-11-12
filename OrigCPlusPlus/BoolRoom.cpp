/********************************************************************
 * Program Filename: BoolRoom.cpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Implementation file for BoolRoom derived from Room
 * Input: Char for interaction function
 * Output: Print room status and prompts
 * *****************************************************************/
 
#include <iostream>
#include <string>
#include "BoolRoom.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;

/****************
* Function Name: Default constructor
* Description: This function is the default constructor for BoolRoom with
* no input parameters. It sets status to false, and the three string data
* members to blank
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
BoolRoom::BoolRoom():Room()
{
	setStatus(false);
	setStatusTrue("");
	setStatusFalse("");
	setPrompt("");
}

/****************
* Function Name: Default constructor
* Description: This function is the default constructor for BoolRoom with
* string input parameters. It sets status to false, and name, type, statusTrue,
* statusFalse, and prompt to the input values
* Parameters: 
*	string iName is the specified name of the room object
*	string iType is the specified type of the room object
*	string iStatT is the specified string for a true status
* 	string iStatF is the specified string for a false status
*	string iPrompt is the specified string to prompt the user
* Pre-Conditions: None
* Post-Conditions: None
****************/
BoolRoom::BoolRoom(string iName, string iType, string iStatT, 
	string iStatF, string iPrompt):Room(iName, iType)
{
	setStatus(false);
	setStatusTrue(iStatT);
	setStatusFalse(iStatF);
	setPrompt(iPrompt);
}

/****************
* Function Name: printStatus
* Description: This function takes no parameters and returns no values.
* It prints the status of the room including the name of the room and the
* status of the type
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
void BoolRoom::printStatus()
{
	cout << "\nYou are in the " << getName() << ". The " << getType();
	cout << " is ";
	
	//Print status statement depending on value of status
	if (getStatus())
		cout << getStatusTrue() << ".";
	else
		cout << getStatusFalse() << ".";
}

/****************
* Function Name: interaction
* Description: This function takes no parameters and returns no values.
* It prompts the user to interact with the room, changes the status, and
* print the new status
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: status changed to true
****************/
void BoolRoom::interaction()
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
	}
}

/****************
* Function Name: setStatus
* Description: This function takes a bool parameter and returns no value.
* It sets the status to the value of the parameter.
* Parameters: bool iStatus is the status for if the task is complete
* Pre-Conditions: None
* Post-Conditions: status changed to true
****************/
void BoolRoom::setStatus(bool iStatus)
{
	status = iStatus;
}

/****************
* Function Name: getStatus
* Description: This function takes no parameters and returns a bool of
* the status member variable.
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
bool BoolRoom::getStatus()
{
	return status;
}

/****************
* Function Name: setStatusTrue
* Description: This function takes a string parameter and returns no value.
* The string parameter is the statement to display if the status is true.
* Parameters: string iStr is the string statement for a true status
* Pre-Conditions: None
* Post-Conditions: None
****************/
void BoolRoom::setStatusTrue(string iStr)
{
	statusTrue = iStr;
}

/****************
* Function Name: getStatusTrue
* Description: This function takes no parameters and returns a string for
* the statement if the status is true
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
string BoolRoom::getStatusTrue()
{
	return statusTrue;
}

/****************
* Function Name: setStatusFalse
* Description: This function takes a string parameter and returns no value.
* The string parameter is the statement to display if the status is false.
* Parameters: string iStr is the string statement for a false status
* Pre-Conditions: None
* Post-Conditions: None
****************/
void BoolRoom::setStatusFalse(string iStr)
{
	statusFalse = iStr;
}

/****************
* Function Name: getStatusFalse
* Description: This function takes no parameters and returns a string for
* the statement if the status is false
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
string BoolRoom::getStatusFalse()
{
	return statusFalse;
}


/****************
* Function Name: setPrompt
* Description: This function takes a string parameter and returns no value.
* The string parameter is the statement to display to prompt the user for action.
* Parameters: string iPrompt is the statement to prompt the user
* Pre-Conditions: 
* Post-Conditions: 
****************/
void BoolRoom::setPrompt(string iPrompt)
{
	prompt = iPrompt;
}

/****************
* Function Name: getPrompt
* Description: This function takes no parameters and returns a string for
* the statement to prompt the user to take action
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
string BoolRoom::getPrompt()
{
	return prompt;
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
