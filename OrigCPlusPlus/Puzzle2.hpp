/********************************************************************
 * Program Filename: Puzzle2.hpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Class declaration for Puzzle2, derived from PuzzleRoom
 * Input: None
 * Output: None
 * *****************************************************************/

#ifndef PUZZLE2_HPP
#define PUZZLE2_HPP

#include "Room.hpp"
#include "PuzzleRoom.hpp"

class Puzzle2:public PuzzleRoom
{
public:
	Puzzle2();
	Puzzle2(string, string);
	virtual void setCombination();
	virtual void interaction();
	virtual void interactionTest();
};

#endif