/********************************************************************
 * Program Filename: House.cpp
 * Author: Alicia Broederdorf
 * Date: June 1, 2015
 * Description: Implementation file for House class
 * Input: Menu selection, item positions, 
 * Output: Print player status, room status, prompts for user, error messages,
 * game status
 * *****************************************************************/
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include "House.hpp"
#include "Room.hpp"
#include "PuzzleRoom.hpp"
#include "Puzzle1.hpp"
#include "Puzzle2.hpp"
#include "Puzzle3.hpp"
#include "ClueBoolRoom.hpp"
#include "BoolRoom.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::random_shuffle;
using std::setw;
using std::left;

/****************
* Function Name: Default constructor
* Description: This is the default constructor. The member variables gameStatus
* and playerLocation will be initialized. All of the room objects will be created, 
* and pointers assigned.
* Parameters: None
* Pre-Conditions: None 
* Post-Conditions: 10 new room objects created
****************/
House::House()
{
	//Initialize vectors
	for (int i = 0; i < 3; i++)
	{
		winningItems.push_back(EMPTY);
		backpack.push_back(EMPTY);
	}
	
	//Test Print
		//cout << "\nHouse Constructor: Initialized vectors.";
	
	//String variables for room constructors
	string puzzleType, lightType, lightT, lightF, lightP, windowType, windowT, windowF, windowP;
	string catType, catT, catF, catP, garbageType, garbageT, garbageF, garbageP;
	string bed1N, bed2N, kitN, bathN, hcN, fcN, studyN, livN, dinN, mrN;
		
	puzzleType = "puzzle";
	lightType = "light";
	lightT = "off";
	lightF = "on";
	lightP = "Would you like to turn the light off?";
	windowType = "window";
	windowT = "closed";
	windowF = "open";
	windowP = "Would you like to close the window?";
	catType = "cat";
	catT = "fed";
	catF = "hungry";
	catP = "Would you like to feed your cat Tiger?";
	garbageType = "garbage";
	garbageT = "taken out";
	garbageF = "piled up";
	garbageP = "Would you like to take the garbage out?";
	bed1N = "first Bedroom";
	bed2N = "second Bedroom";
	kitN = "Kitchen";
	bathN = "Bathoom";
	hcN = "Hall Closet";
	fcN = "Front Closet";
	studyN = "Study";
	livN = "Living Room";
	dinN = "Dining Room";
	mrN = "Mud Room";
	
	//Create rooms
	bed1 = new Puzzle1(bed1N, puzzleType);
	bed2 = new Puzzle2(bed2N, puzzleType);
	kitchen = new Puzzle3(kitN, puzzleType);
	bathroom = new ClueBoolRoom(bathN, lightType, lightT, lightF, lightP);
	hallCloset = new ClueBoolRoom(hcN, lightType, lightT, lightF, lightP);
	dining = new BoolRoom(dinN, catType, catT, catF, catP);
	living = new ClueBoolRoom(livN, windowType, windowT, windowF, windowP);
	frontCloset = new ClueBoolRoom(fcN, lightType, lightT, lightF, lightP);
	study = new ClueBoolRoom(studyN, windowType, windowT, windowF, windowP);
	mudRoom = new BoolRoom(mrN, garbageType, garbageT, garbageF, garbageP);
		
	//Assign pointers
	//Bed1
	bed1->setSouth(kitchen);
	bed1->setWest(bathroom);
	
	//Bed2
	bed2->setSouth(hallCloset);
	bed2->setEast(bathroom);
	
	//Bathroom
	bathroom->setSouth(dining);
	bathroom->setWest(bed2);
	bathroom->setEast(bed1);
	
	//hallCloset
	hallCloset->setNorth(bed2);
	hallCloset->setEast(dining);
	hallCloset->setSouth(living);
	
	//Dining
	dining->setNorth(bathroom);
	dining->setSouth(frontCloset);
	dining->setWest(hallCloset);
	dining->setEast(kitchen);
	
	//Kitchen
	kitchen->setNorth(bed1);
	kitchen->setWest(dining);
	kitchen->setSouth(study);
	
	//Living
	living->setNorth(hallCloset);
	living->setEast(frontCloset);
	
	//Front Closet
	frontCloset->setNorth(dining);
	frontCloset->setWest(living);
	frontCloset->setSouth(mudRoom);
	frontCloset->setEast(study);
	
	//Study
	study->setNorth(kitchen);
	study->setWest(frontCloset);
	
	//Mud Room
	mudRoom->setNorth(frontCloset);
	
	//Initialize member data
	setGameStatus(false);
	playerLocation = mudRoom;
	
	//Test Print
		//cout << "\nHouse Constructor: Initialized data.";
	
	//Test print
		//cout << "\nHouse constructor complete";
}

/****************
* Function Name: Destructor
* Description: This destructor deletes all of the rooms allocated in 
* the constructor
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: All rooms deleted and pointers assigned NULL
****************/
House::~House()
{
	//Delete bed1
	Room *garbage1;
	garbage1 = bed1;
	bed1 = NULL;
	delete garbage1;
	
	//Delete bed2
	Room *garbage2;
	garbage2 = bed2;
	bed2 = NULL;
	delete garbage2;
	
	//Delete bathroom
	Room *garbage3;
	garbage3 = bathroom;
	bathroom = NULL;
	delete garbage3;
	
	//Delete hallCloset
	Room *garbage4;
	garbage4 = hallCloset;
	hallCloset = NULL;
	delete garbage4;
	
	//Delete dining
	Room *garbage5;
	garbage5 = dining;
	dining = NULL;
	delete garbage5;
	
	//Delete kitchen
	Room *garbage6;
	garbage6 = kitchen;
	kitchen = NULL;
	delete garbage6;
	
	//Delete living
	Room *garbage7;
	garbage7 = living;
	living = NULL;
	delete garbage7;
	
	//Delete frontCloset
	Room *garbage8;
	garbage8 = frontCloset;
	frontCloset = NULL;
	delete garbage8;
	
	//Delete study
	Room *garbage9;
	garbage9 = study;
	study = NULL;
	delete garbage9;
	
	//Delete mudRoom
	Room *garbage10;
	garbage10 = mudRoom;
	mudRoom = NULL;
	delete garbage10;
}

/****************
* Function Name: setGameStatus
* Description: This function takes a bool parameter and returns no value.
* It sets the member variable gameStatus to the input
* Parameters: bool iStatus is the status of the game
* Pre-Conditions: None
* Post-Conditions: None
****************/
void House::setGameStatus(bool iStatus)
{
	gameStatus = iStatus;
}

/****************
* Function Name: getGameStatus
* Description: This function takes no input parameters and returns a bool
* for the gameStatus member variable
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
bool House::getGameStatus()
{
	return gameStatus;
}

/****************
* Function Name: navigate
* Description: This function takes no parameters and returns no value.
* It prompts the user for the direction to navigate, if wall encountered
* message is printed, otherwise playerLocation is changed to room in the
* specified direction
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: playerLocation changed if direction is not NULL
****************/
void House::navigate()
{
	char userInput;
	
	//Prompt user for choice
	cout << "\nWhich direction would you like to move in? Please enter N (north),";
	cout << "\nS (south), E (east), or W (west): ";
	cin.get(userInput);
	cin.clear();
	cin.ignore(1000,'\n');
	
	//Validate input
	while (toupper(userInput) != 'N' && toupper(userInput) != 'S' && 
			toupper(userInput) != 'E' && toupper(userInput) != 'W')
	{
		cout << "Error: Invalid input. Please enter N, S, E, or W: ";
		cin.get(userInput);
		cin.clear();
		cin.ignore(1000,'\n');
	}
	
	//Check if that direction is null, if not, change location
	if (toupper(userInput) == 'N')
	{
		if (playerLocation->getNorth() == NULL)
			cout << "\nYou hit a wall, go a different direction.";
		else
			playerLocation = playerLocation->getNorth();
	}
	else if (toupper(userInput) == 'S')
	{
		if (playerLocation->getSouth() == NULL)
		{
			if (playerLocation == mudRoom)
			{
				cout << "\nThat's the front door, if you want to leave,";
				cout << " select option 6 from the menu.";
			}
			else
				cout << "\nYou hit a wall, go a different direction.";
		}
		else
			playerLocation = playerLocation->getSouth();
	}
	else if (toupper(userInput) == 'E')
	{
		if (playerLocation->getEast() == NULL)
			cout << "\nYou hit a wall, go a different direction.";
		else
			playerLocation = playerLocation->getEast();
	}
	else
	{
		if (playerLocation->getWest() == NULL)
			cout << "\nYou hit a wall, go a different direction.";
		else
			playerLocation = playerLocation->getWest();
	}	
	
	//Print room status
	playerLocation->printStatus();
}

/****************
* Function Name: playerStatus
* Description: This function takes no parameters and returns no values.
* It prints the players current location and the items in the backpack.
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
void House::playerStatus()
{
	//Print player's location
	cout << "\nYou are currently in the " << playerLocation->getName();
	
	//Print items in backpack
	cout << "\nThe items in your backpack are:";
	if (backpack.size() == 0)
		cout << "\nYou do not have any items yet.";
	else
	{
		for (int i = 0; i < backpack.size(); i++)
		{
			if (backpack[i] == MAP)
				cout << "\n" << i+1 << ". Map";
			else if (backpack[i] == COMPASS)
				cout << "\n" << i+1 << ". Compass";
			else if (backpack[i] == SUNGLASSES)
				cout << "\n" << i+1 << ". Sunglasses";
			else if (backpack[i] == JACKET)
				cout << "\n" << i+1 << ". Jacket";
			else if (backpack[i] == HEADLAMP)
				cout << "\n" << i+1 << ". Headlamp";
			else if (backpack[i] == FIRSTAID)
				cout << "\n" << i+1 << ". First aid";
			else if (backpack[i] == FIRESTARTER)
				cout << "\n" << i+1 << ". Firestarter";
			else if (backpack[i] == MATCHES)
				cout << "\n" << i+1 << ". Matches";
			else if (backpack[i] == KNIFE)
				cout << "\n" << i+1 << ". Knife";
			else if (backpack[i] == SNICKERSBAR)
				cout << "\n" << i+1 << ". Snickers bar";
			else
				cout << "\n" << i+1 << ". Empty";
		}
		
		//Test print
			//cout << "\nSize of backpack is: " << backpack.size();
	}		
}

/****************
* Function Name: checkGame
* Description: This function takes no parameters and returns no value.
* It checks to make sure all bool status is true for bool rooms and that
* the backpack contains the three winning items.
* Parameters: None
* Pre-Conditions: None 
* Post-Conditions: None
****************/
void House::checkGame()
{
	int totalBool = 0;
	int totalItems = 0;
	
	//Test print
		//cout << "\nSize of backpack: " << backpack.size();
		//cout << ", size of winning: " << winningItems.size();
	
	//Check bool rooms
	if (!static_cast<BoolRoom *>(bathroom)->getStatus())
		totalBool++;
	if (!static_cast<BoolRoom *>(hallCloset)->getStatus())
		totalBool++;
	if (!static_cast<BoolRoom *>(dining)->getStatus())
		totalBool++;
	if (!static_cast<BoolRoom *>(living)->getStatus())
		totalBool++;
	if (!static_cast<BoolRoom *>(frontCloset)->getStatus())
		totalBool++;
	if (!static_cast<BoolRoom *>(study)->getStatus())
		totalBool++;
	if (!static_cast<BoolRoom *>(mudRoom)->getStatus())
		totalBool++;	

	//Check items
	if (backpack.size() != 3)
		totalItems = -1;
	else
	{
		for (int i = 0; i < backpack.size(); i++)
		{
			for (int j = 0; j < winningItems.size(); j++)
			{
				if (backpack[i] == winningItems[j])
					totalItems++;
			}
		}
	}
	
	//Test print
		//cout << "\nTotal bool: " << totalBool << " and Total items: " << totalItems;
	
	//Print status
	if (totalBool != 0)
	{
		if (totalItems == -1)
		{
			cout << "\nYou can't leave yet, you have unfinished house tasks and";
			cout << "\nyou haven't packed your 3 missing ten essentials.";
		}
		else if (totalItems == 0)
		{
			cout << "\nYou can't leave yet, you have unfinished house tasks and all";
			cout << "\nof your items are incorrect.";
		}
		else if (totalItems == 1)
		{
			cout << "\nYou can't leave yet, you have unfinished house tasks and two";
			cout << "\nof your items are incorrect.";
		}
		else if (totalItems == 2)
		{
			cout << "\nYou can't leave yet, you have unfinished house tasks and one";
			cout << "\nof your items is incorrect.";
		}
		else 
			cout << "\nYou can't leave yet, you have unfinished house tasks.";
	}
	else
	{
		if (totalItems == -1)
		{
			cout << "\nYou can't leave yet, you haven't packed your 3 missing ten essentials.";
		}
		else if (totalItems == 0)
		{
			cout << "\nYou can't leave yet, all of your items are incorrect.";
		}
		else if (totalItems == 1)
		{
			cout << "\nYou can't leave yet, two of your items are incorrect.";
		}
		else if (totalItems == 2)
		{
			cout << "\nYou can't leave yet, one of your items is incorrect.";
		}
		else if (totalItems == 3)
		{
			cout << "\nCongratulations, you finished the house tasks and packed your three missing items.";
			cout << "\nHave fun camping with your friends!";
			setGameStatus(true);
		}
		else
			cout << "\nError: Total Items not 0, 1, 2, or 3.";
	}
	
	//Test print
		//cout << "\nSize of backpack: " << backpack.size();
		//cout << ", size of winning: " << winningItems.size();
}

/****************
* Function Name: menu
* Description: This function takes no parameters and returns no value.
* It displays the menu, gets the user's selection, and calls the appropriate function.
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
void House::menu()
{
	int userChoice;
	string userChoiceStr;
	char userInput;
	bool inputVal = true;

	//Print menu options and get user's selection
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\nMenu:";
	cout << "\n1) Print player status";
	cout << "\n2) Print room status";
	cout << "\n3) Complete task or find item";
	cout << "\n4) Navigate";
	cout << "\n5) Print map";
	cout << "\n6) Exit front door";
	cout << "\n7) Quit Game";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\nPlease enter your selection: ";
	
	//Validate input
	do
	{
		inputVal = true;
		getline(cin,userChoiceStr);
		cin.clear();
	
		//Validate input is integer
		while(!intValidate(userChoiceStr))
		{
			cout << "\nError: invalid input. Please enter integer 1, 2, 3, 4, 5, 6, or 7: ";
			getline(cin,userChoiceStr);
			cin.clear();
		}
		
		//Convert string to integer
			userChoice = strToInt(userChoiceStr);
		
		//Validate input is in valid range
		if (userChoice < 1 || userChoice > 7)
		{
			cout << "\nError: invalid input. Please enter 1, 2, 3, 4, 5, 6, or 7: ";
			inputVal = false;
		}
	}while(!inputVal);
		
	//Call appropriate function
	//Print player status
	if (userChoice == 1)
		playerStatus();
		
	//Print room status
	else if (userChoice == 2)
		playerLocation->printStatus();
		
	//Interact with room
	else if (userChoice == 3)
	{
		//Check if room is puzzle
		playerLocation->interaction();
		if (playerLocation->getType() == "puzzle")
		{
			if (static_cast<PuzzleRoom *>(playerLocation)->getCabinetOpen())
			{
				cout << "\nWould you like to add one of these items to your backpack? (Y/N) ";
				cin.get(userInput);
				cin.clear();
				cin.ignore(1000,'\n');
				//Validate input
				while (toupper(userInput) != 'N' && toupper(userInput) != 'Y')
				{
					cout << "Error: Invalid input. Please enter Y or N: ";
					cin.get(userInput);
					cin.clear();
					cin.ignore(1000,'\n');
				}
				
				//Call add item function
				if (toupper(userInput) == 'Y')
					addItem();
			}
		}
	}
	
	//Navigate
	else if (userChoice == 4)
		navigate();
		
	//Print map
	else if (userChoice == 5)
		printMap();
		
	//Exit front door
	else if (userChoice == 6)
	{
		//See if player is in mud room, then check game status
		if (playerLocation == mudRoom)
			checkGame();
		else
			cout << "\nError: You must be in the mud room before you try to exit the front door.";
	}
	
	//Quit game
	else if (userChoice == 7)
		setGameStatus(true);
		
	//Invalid input
	else
		cout << "\nError: invalid input. Select integer from 1 to 7";
}

/****************
* Function Name: addItem
* Description: This function takes no parameters and returns no values.
* It prompts the user and completes the actions to add an item to the backpack.
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
void House::addItem()
{
	int backPos, cabPos, maxItems;
	
	//Prompt user for which item # in backpack to put item
	cout << "Would you like to put the item in position 1, 2, or 3 of your backpack? ";
	cin >> backPos;
	cin.clear();
	cin.ignore(1000,'\n');
	
	//Validate input is 1, 2, or 3
	while (backPos != 1 && backPos != 2 && backPos != 3)
	{
		cout << "\nError: invalid input. Please enter 1, 2, or 3: ";
		cin >> backPos;
		cin.clear();
		cin.ignore(1000,'\n');
	}
	
	//Prompt user for which item # from cabinet
	cout << "Which item number from the cabinet would you like? ";
	cin >> cabPos;
	cin.clear();
	cin.ignore(1000,'\n');
	
	//Validate input
	if (playerLocation == bed1)
	{
		while (cabPos != 1 && cabPos != 2 && cabPos != 3 && cabPos !=4)
		{
			cout << "\nError: invalid input. Please enter an integer from 1 to 4: ";
			cin >> cabPos;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}
	else
	{
		while (cabPos != 1 && cabPos != 2 && cabPos != 3)
		{
			cout << "\nError: invalid input. Please enter an integer from 1 to 3: ";
			cin >> cabPos;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}
	
	//Add item to backpack
	backpack[backPos-1] = static_cast<PuzzleRoom *>(playerLocation)->getItem(cabPos-1);
	
	//Print player status
	cout << "\nItem is added. Here is your updated status: ";
	playerStatus();
}

/****************
* Function Name: assignItems
* Description: This function takes no parameters and returns no values.
* It shuffles a vector containing all of the items. It assigns the first
* three items to the winningItems vector, and assigns the next 5 items'
* clue statement to the ClueBoolRoom rooms.
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
void House::assignItems()
{
	//Create vector of all items
	vector <essentials> allItems;
	allItems.push_back(MAP);
	allItems.push_back(COMPASS);
	allItems.push_back(SUNGLASSES);
	allItems.push_back(JACKET);
	allItems.push_back(HEADLAMP);
	allItems.push_back(FIRSTAID);
	allItems.push_back(FIRESTARTER);
	allItems.push_back(MATCHES);
	allItems.push_back(KNIFE);
	allItems.push_back(SNICKERSBAR);
	
	//Shuffle vector
	random_shuffle(allItems.begin(), allItems.end());
	
	//Assign first three items to winningItems vector
	for (int i = 0; i < 3; i++)
		winningItems[i] = allItems[i];
	
	//Assign clue statements to rooms
	static_cast<ClueBoolRoom *>(bathroom)->setClue(getCluePhrase(allItems[3]));
	static_cast<ClueBoolRoom *>(hallCloset)->setClue(getCluePhrase(allItems[4]));
	static_cast<ClueBoolRoom *>(living)->setClue(getCluePhrase(allItems[5]));
	static_cast<ClueBoolRoom *>(frontCloset)->setClue(getCluePhrase(allItems[6]));
	static_cast<ClueBoolRoom *>(study)->setClue(getCluePhrase(allItems[7]));
}

/****************
* Function Name: getCluePhrase
* Description: This function takes no parameters and returns no values.
* It returns a string for the clue phrase associated with each essentials
* item
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
string House::getCluePhrase(essentials itemIn)
{
	if (itemIn == MAP)
		return "I won't get lost with my map.";
	else if (itemIn == COMPASS)
		return "Compass, check. How do you use this thing again?";
	else if (itemIn == SUNGLASSES)
		return "I've got my sunglasses.";
	else if (itemIn == JACKET)
		return "I'll be warm with my new jacket packed.";
	else if (itemIn == HEADLAMP)
		return "The dark is less scary with my powerful headlamp packed.";
	else if (itemIn == FIRSTAID)
		return "Don't fall, but just in case, the first aid kit is packed.";
	else if (itemIn == FIRESTARTER)
		return "Roaring fires start with good fire starter, check.";
	else if (itemIn == MATCHES)
		return "Matches are packed.";
	else if (itemIn == KNIFE)
		return "My pocket knife is secured in the cap of my pack.";
	else
		return "Mmmm, my favorite camping treat. Is having 3 Snickers bars packed excessive?";
}

/****************
* Function Name: printMap
* Description: This function takes no parameters and returns no values.
* It prints the map of the house and the current location of the player
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
void House::printMap()
{
	//Strings to print
	string a = " --- ---- --- ";
	string b = "|   |    |   |";
	string c = "| 1 | 2  | 3 |\t1: Bedroom 2  \t2: Bathroom   \t3: Bedroom 1";
	string d = "| 4 | 5  | 6 |\t4: Hall Closet\t5: Dining Room\t6: Kitchen";
	string e = "| 7 | 8  | 9 |\t7: Living Room\t8: Front Closet\t9: Study";
	string f = "    |    |    ";
	string g = "    | 10 |    \t10: Mud Room";
	string h = "     ----     ";
	
	//Print map
	cout << "\n" << a;
	//cout << "\n" << b;
	cout << "\n" << c;
	//cout << "\n" << b;
	cout << "\n" << a;
	//cout << "\n" << b;
	cout << "\n" << d;
	//cout << "\n" << b;
	cout << "\n" << a;
	//cout << "\n" << b;
	cout << "\n" << e;
	//cout << "\n" << b;
	cout << "\n" << a;
	//cout << "\n" << f;
	cout << "\n" << g;
	//cout << "\n" << f;
	cout << "\n" << h;
	cout << "\n      /       ";
	cout << "\n  Front Door  ";
	
	//Print player's location
	cout << "\n\nYou are currently in the " << playerLocation->getName();
	
}

/****************
* Function Name: menuTest
* Description: This function takes no parameters and returns no value.
* It displays the menu, gets the user's selection, and calls the appropriate function.
* For the test part, it displays what the three winning items are
* Parameters: None
* Pre-Conditions: None
* Post-Conditions: None
****************/
void House::menuTest()
{
	int userChoice;
	string userChoiceStr;
	char userInput;
	bool inputVal = true;

	//Print menu options and get user's selection
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\nMenu:";
	cout << "\n1) Print player status";
	cout << "\n2) Print room status";
	cout << "\n3) Complete task or find item";
	cout << "\n4) Navigate";
	cout << "\n5) Print map";
	cout << "\n6) Exit front door";
	cout << "\n7) Quit Game";
	//Print winning items
	cout << "\nThe winning items are: ";
	for (int i = 0; i < winningItems.size(); i++)
		{
			if (winningItems[i] == MAP)
				cout <<  "Map   ";
			else if (winningItems[i] == COMPASS)
				cout << "Compass   ";
			else if (winningItems[i] == SUNGLASSES)
				cout << "Sunglasses   ";
			else if (winningItems[i] == JACKET)
				cout << "Jacket   ";
			else if (winningItems[i] == HEADLAMP)
				cout << "Headlamp   ";
			else if (winningItems[i] == FIRSTAID)
				cout << "First aid   ";
			else if (winningItems[i] == FIRESTARTER)
				cout << "Firestarter   ";
			else if (winningItems[i] == MATCHES)
				cout << "Matches   ";
			else if (winningItems[i] == KNIFE)
				cout << "Knife   ";
			else if (winningItems[i] == SNICKERSBAR)
				cout << "Snickers bar   ";
			else
				cout << "Empty   ";
		}
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\nPlease enter your selection: ";
	
	//Validate input
	do
	{
		inputVal = true;
		getline(cin,userChoiceStr);
		cin.clear();
	
		//Validate input is integer
		while(!intValidate(userChoiceStr))
		{
			cout << "\nError: invalid input. Please enter integer 1, 2, 3, 4, 5, 6, or 7: ";
			getline(cin,userChoiceStr);
			cin.clear();
		}
		
		//Convert string to integer
			userChoice = strToInt(userChoiceStr);
		
		//Validate input is in valid range
		if (userChoice < 1 || userChoice > 7)
		{
			cout << "\nError: invalid input. Please enter 1, 2, 3, 4, 5, 6, or 7: ";
			inputVal = false;
		}
	}while(!inputVal);
	
	//Call appropriate function
	//Print player status
	if (userChoice == 1)
		playerStatus();
		
	//Print room status
	else if (userChoice == 2)
		playerLocation->printStatus();
		
	//Interact with room
	else if (userChoice == 3)
	{
		//Check if room is puzzle
		
		if (playerLocation->getType() == "puzzle")
		{
			//Call test interaction functions of puzzle rooms
			static_cast<PuzzleRoom *>(playerLocation)->interactionTest();
		
			//If cabinet door is open, prompt user if he/she wants to add item
			if (static_cast<PuzzleRoom *>(playerLocation)->getCabinetOpen())
			{
				cout << "\nWould you like to add one of these items to your backpack? (Y/N) ";
				cin.get(userInput);
				cin.clear();
				cin.ignore(1000,'\n');
				//Validate input
				while (toupper(userInput) != 'N' && toupper(userInput) != 'Y')
				{
					cout << "Error: Invalid input. Please enter Y or N: ";
					cin.get(userInput);
					cin.clear();
					cin.ignore(1000,'\n');
				}
				
				//Call add item function
				if (toupper(userInput) == 'Y')
					addItem();
			}
		}
		else
			playerLocation->interaction();
	}
	
	//Navigate
	else if (userChoice == 4)
		navigate();
				
	//Print map
	else if (userChoice == 5)
		printMap();
		
	//Exit front door
	else if (userChoice == 6)
	{
		//See if player is in mud room, then check game status
		if (playerLocation == mudRoom)
			checkGame();
		else
			cout << "\nError: You must be in the mud room before you try to exit the front door.";
	}
	
	//Quit game
	else if (userChoice == 7)
		setGameStatus(true);
		
	//Invalid input
	else
		cout << "\nError: invalid input. Select integer from 1 to 7";
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
