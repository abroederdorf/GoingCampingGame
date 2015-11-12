/********************************************************************
 * Program Filename: Puzzle1.hpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Class declaration for Puzzle1, derived from PuzzleRoom
 * Input: None
 * Output: None
 * *****************************************************************/

#ifndef PUZZLE1_HPP
#define PUZZLE1_HPP

#include "Room.hpp"
#include "PuzzleRoom.hpp"

class Puzzle1:public PuzzleRoom
{
public:
	Puzzle1();
	Puzzle1(string, string);
	virtual void setCombination();
	virtual void interaction();
	virtual void interactionTest();
};

#endif