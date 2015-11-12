/********************************************************************
 * Program Filename: Room.cpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Implementation file for Room
 * Input: None
 * Output: None
 * *****************************************************************/
 
#include <iostream>
#include <string>
#include "Room.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;

/****************
* Function Name: setName
* Description: This function takes a string parameter and returns
* no value. It sets the name member variable to the input
* Parameters: string iName is the specified name of the room object
* Pre-Conditions: None
* Post-Conditions: None
****************/
void Room::setName(string iName)
{
	setName(iName);
}

/****************
* Function Name: getName
* Description: This function takes no parameters and returns a string
* for the room name
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
string Room::getName()
{
	return name;
}

/****************
* Function Name: setType
* Description: This function takes a string parameter and returns
* no value. It sets the type member variable to the input
* Parameters: string iType is the specified type of the room object
* Pre-Conditions: None
* Post-Conditions: None
****************/
void Room::setType(string iType)
{
	setName(iType);
}

/****************
* Function Name: getType
* Description: This function takes no parameters and returns a string
* for the room type
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
string Room::getType()
{
	return type;
}

/****************
* Function Name: setNorth
* Description: This function takes a Room pointer as a parameter and
* returns no values. It sets the north pointer data member to the
* room to the north, or sets it to NULL if there is no room
* Parameters: Room *northRm is the pointer to the room to the north
* Pre-Conditions: None
* Post-Conditions: None
****************/
void Room::setNorth(Room *northRm)
{
	north = northRm;
}

/****************
* Function Name: getNorth
* Description: This function takes no parameters and returns a Room pointer
* to the room to the north.
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
Room * Room::getNorth()
{
	return north;
}


/****************
* Function Name: setSouth
* Description: This function takes a Room pointer as a parameter and
* returns no values. It sets the south pointer data member to the
* room to the south, or sets it to NULL if there is no room
* Parameters: Room *southRm is the pointer to the room to the south
* Pre-Conditions: None
* Post-Conditions: None
****************/
void Room::setSouth(Room *southRm)
{
	south = southRm;
}

/****************
* Function Name: getSouth
* Description: This function takes no parameters and returns a Room pointer
* to the room to the south.
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
Room * Room::getSouth()
{
	return south;
}


/****************
* Function Name: setEast
* Description: This function takes a Room pointer as a parameter and
* returns no values. It sets the east pointer data member to the
* room to the east, or sets it to NULL if there is no room
* Parameters: Room *eastRm is the pointer to the room to the east
* Pre-Conditions: None
* Post-Conditions: None
****************/
void Room::setEast(Room *eastRm)
{
	east = eastRm;
}

/****************
* Function Name: getEast
* Description: This function takes no parameters and returns a Room pointer
* to the room to the east.
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
Room * Room::getEast()
{
	return east;
}


/****************
* Function Name: setWest
* Description: This function takes a Room pointer as a parameter and
* returns no values. It sets the west pointer data member to the
* room to the west, or sets it to NULL if there is no room
* Parameters: Room *westRm is the pointer to the room to the west
* Pre-Conditions: None
* Post-Conditions: None
****************/
void Room::setWest(Room *westRm)
{
	west = westRm;
}

/****************
* Function Name: getWest
* Description: This function takes no parameters and returns a Room pointer
* to the room to the west.
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
Room * Room::getWest()
{
	return west;
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


