/********************************************************************
 * Program Filename: PuzzleRoom.hpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Class declaration for PuzzleRoom, derived from Room
 * Input: None
 * Output: None
 * *****************************************************************/

#ifndef PUZZLEROOM_HPP
#define PUZZLEROOM_HPP

#include <string>
#include <vector>
#include "Room.hpp"
using std::string;
using std::vector;

class PuzzleRoom:public Room
{
protected:
	vector <essentials> items;
	int combination;
	bool cabinetOpen;
public:
	PuzzleRoom();
	PuzzleRoom(string, string);
	virtual void printStatus();
	virtual void setCombination() = 0;
	virtual void interactionTest() = 0;
	int getCombination();
	void printItems();
	essentials getItem(int);
	void setCabinetOpen(bool);
	bool getCabinetOpen();
};

#endif