/********************************************************************
 * Program Filename: PuzzleRoom.cpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Implementation file for PuzzleRoom, derived from Room
 * Input: Characters for user choice and string for combination
 * Output: Print room status, objective, list of items, and if user 
 * guess is correct
 * *****************************************************************/
 
#include <iostream>
#include <string>
#include <vector>
#include "PuzzleRoom.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

/****************
* Function Name: Default constructor
* Description: This function is the default constructor for PuzzleRoom with
* no input parameters. It sets the type to puzzle and initializes the 
* combination to 0
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
PuzzleRoom::PuzzleRoom():Room()
{
	combination = 0;
	cabinetOpen = false;
}

/****************
* Function Name: Default constructor
* Description: This function is the default constructor for PuzzleRoom with
* two string input parameters. It initializes the combination to 0
* Parameters: 
*	string iName is the specified name of the room object
*	string iType is the specified type of the room object
* Pre-Conditions: None
* Post-Conditions: None
****************/
PuzzleRoom::PuzzleRoom(string iName, string iType):Room(iName, iType)
{
	combination = 0;
	cabinetOpen = false;
}

/****************
* Function Name: printStatus
* Description: This function takes no parameters and returns no values.
* It prints the status of the room including the name of the room and that
* there is a locked cabinet
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
void PuzzleRoom::printStatus()
{
	cout << "\nYou are in the " << getName() << ". You find a locked cabinet.";
}

/****************
* Function Name: getCombination
* Description: This function takes no parameters and returns an integer for
* the combination
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
int PuzzleRoom::getCombination()
{
	return combination;
}

/****************
* Function Name: printItems
* Description: This function takes no parameters and returns no values.
* It prints the items stored in the room
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
void PuzzleRoom::printItems()
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] == MAP)
			cout << "\n" << i+1 << ". Map";
		else if (items[i] == COMPASS)
			cout << "\n" << i+1 << ". Compass";
		else if (items[i] == SUNGLASSES)
			cout << "\n" << i+1 << ". Sunglasses";
		else if (items[i] == JACKET)
			cout << "\n" << i+1 << ". Jacket";
		else if (items[i] == HEADLAMP)
			cout << "\n" << i+1 << ". Headlamp";
		else if (items[i] == FIRSTAID)
			cout << "\n" << i+1 << ". First aid";
		else if (items[i] == FIRESTARTER)
			cout << "\n" << i+1 << ". Firestarter";
		else if (items[i] == MATCHES)
			cout << "\n" << i+1 << ". Matches";
		else if (items[i] == KNIFE)
			cout << "\n" << i+1 << ". Knife";
		else if (items[i] == SNICKERSBAR)
			cout << "\n" << i+1 << ". Snickers bar";
		else
			cout << "\n" << i+1 << ". ERROR";
	}
}

/****************
* Function Name: getItem
* Description: This function takes an integer parameter to indicate the
* position of the item, and returns an essential data type of the item at
* that position
* Parameters: int pos is the integer representing the position of the item
* Pre-Conditions: Position input is valid, within range of vector
* Post-Conditions: None
****************/
essentials PuzzleRoom::getItem(int pos)
{
		return items[pos];
}

/****************
* Function Name: setCabinetOpen
* Description: This function takes a bool parameter to indicate if the cabient
* door is open (combination is guessed), set sets that to the member variable.
* It returns no value.
* Parameters: bool iStatus is true if the cabinet door is open
* Pre-Conditions: None
* Post-Conditions: None
****************/
void PuzzleRoom::setCabinetOpen(bool iStatus)
{
	cabinetOpen = iStatus;
}

/****************
* Function Name: getCabinetOpen
* Description: This function takes no parameters and returns a bool for the status
* of the cabinetOpen data member.
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
bool PuzzleRoom::getCabinetOpen()
{
	return cabinetOpen;
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
