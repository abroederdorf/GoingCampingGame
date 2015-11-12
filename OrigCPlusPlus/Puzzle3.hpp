/********************************************************************
 * Program Filename: Puzzle3.hpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Class declaration for Puzzle3, derived from PuzzleRoom
 * Input: None
 * Output: None
 * *****************************************************************/

#ifndef PUZZLE3_HPP
#define PUZZLE3_HPP

#include "Room.hpp"
#include "PuzzleRoom.hpp"

class Puzzle3:public PuzzleRoom
{
private:
	int combTotal;
public:
	Puzzle3();
	Puzzle3(string, string);
	virtual void setCombination();
	virtual void interaction();
	virtual void interactionTest();
};

#endif