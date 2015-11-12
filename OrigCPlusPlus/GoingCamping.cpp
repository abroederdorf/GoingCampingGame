/********************************************************************
 * Program Filename: GoingCamping.cpp
 * Author: Alicia Broederdorf
 * Date: June 1, 2015
 * Description: This is the client program for Going Camping where functions
 * from the house class are called to run the game.
 * To implement time feature, used http://www.cplusplus.com/reference/ctime/time/
 * as reference.
 * Input: None
 * Output: Game description is printed
 * *****************************************************************/
 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "House.hpp"
#include "Room.hpp"
#include "PuzzleRoom.hpp"
#include "Puzzle1.hpp"
#include "Puzzle2.hpp"
#include "Puzzle3.hpp"
#include "ClueBoolRoom.hpp"
#include "BoolRoom.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::setprecision;
using std::fixed;

int main()
{
	House goingCamping;
	int userChoice, timeMinutes;
	double diffTimeSeconds, timeRemaining, timeSeconds;
	time_t timerStart;
	time_t timerNow;
	
	//Create seed for rand function used for dice rolls
	unsigned seed; 
	seed=time(0);
	srand(seed);
	
	//Assign winning items to goingCamping
	goingCamping.assignItems();
	
	//Print game description and objective
	cout << "\nGoing Camping";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\nYou are about to leave on a camping trip in the mountains, however, you forgot";
	cout << "\nto pack three of the ten essentials and you need to get your house ready before";
	cout << "\nyour friends arrive in 10 minutes to pick you up.\n";
	cout << "\nObjective: ";
	cout << "\nYou must pack the three remaining ten essentials in your backpack, close the";
	cout << "\nwindows, turn off all the lights, feed the cat, and take the garbage out before";
	cout << "\nyou can exit the front door to meet your friends.\n";
	cout << "\nDescription: ";
	cout << "\nNavigate through the house to find which rooms have open windows to close and";
	cout << "\nlights on that should be turned off. Find your cat Tiger and feed her, as well";
	cout << "\nas take out the garbage. Three of the rooms contain a locked cabinet that your";
	cout << "\ngear is stored in. You must choose the correct three items to be able to leave";
	cout << "\nwith your friends. You'll have to figure out the combination every time you want";
	cout << "\nto open the cabinet. When you think you have the house prepared and the three";
	cout << "\nmissing items packed in your backpack, try to exit the front door. If you are";
	cout << "\ncorrect you will successfully meet your friends, otherwise you'll have to go";
	cout << "\nback and choose the correct item(s) or complete the unfinished house task(s).";
	cout << "\nYou are only allowed three items in your backpack at a time from the ten that";
	cout << "\nare stored in the cabinets. Be on the lookout for clues along the the way!\n";
	goingCamping.printMap();
	cout << "\n\nPlay Modes: Normal or Test. Test displays the combinations and the winning items.";
	cout << "\nPlease select normal mode (1) or test mode (2): ";
	cin >> userChoice;
	cin .clear();
	cin.ignore(1000,'\n');
	
	cout << "\n\nGood luck, time starts now!\n";
	
	//Get start time
	time(&timerStart);
	
	if (userChoice == 1)
	{
		while (!goingCamping.getGameStatus())
		{
			//Call menu
			goingCamping.menu();
		
			//Calculate time
			time(&timerNow);
			diffTimeSeconds = difftime(timerNow, timerStart);
			timeRemaining = 10.0 - diffTimeSeconds/60.0;
			timeMinutes = static_cast<int>(timeRemaining);
			timeSeconds = (timeRemaining - timeMinutes) * 60.0;
			
			//Check time and print time remaining
			if (timeRemaining < 0.0)
			{
				cout << "\nI'm sorry but you've run out of time and your friends";
				cout << " left without you. \nBetter luck next time." << endl;
				goingCamping.setGameStatus(true);
			}
			else
			{
				cout << "\nTime remaining: " << timeMinutes;
				//Print seconds
				if (timeSeconds < 10)
					cout << ":0" << fixed << setprecision(0) << timeSeconds;
				else
					cout << ":" << fixed << setprecision(0) << timeSeconds;
			}
		}
	}
	else if (userChoice == 2)
	{
		while (!goingCamping.getGameStatus())
			goingCamping.menuTest();
	}
	else
		cout << "\nError: invalid input. Game is ending now." << endl;
	
	cout << "\nThanks for playing, have a great day!" << endl;
	
	cout << endl;
	return 0;
}

/****************
* Function Name: 
* Description: 
* Parameters: 
* Pre-Conditions: 
* Post-Conditions: 
****************/
