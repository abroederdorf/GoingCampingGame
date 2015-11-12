/********************************************************************
 * Program Filename: House.hpp
 * Author: Alicia Broederdorf
 * Date: June 1, 2015
 * Description: Class declaration for House
 * Input: None
 * Output: None
 * *****************************************************************/

#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <vector>
#include <string>
#include "Room.hpp"
using std::vector;
using std::string;

class House
{
private:
	Room *bed1;
	Room *bed2;
	Room *bathroom;
	Room *hallCloset;
	Room *dining;
	Room *kitchen;
	Room *living;
	Room *frontCloset;
	Room *study;
	Room *mudRoom;
	Room *playerLocation;
	vector <essentials> backpack;
	vector <essentials> winningItems;
	bool gameStatus;
public:
	House();
	~House();
	void setGameStatus(bool);
	bool getGameStatus();
	void navigate();
	void playerStatus();
	void checkGame();
	void menu();
	void addItem();
	void assignItems();
	string getCluePhrase(essentials);
	void printMap();
	void menuTest();
};

#endif