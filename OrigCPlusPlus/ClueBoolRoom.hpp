/********************************************************************
 * Program Filename: ClueBoolRoom.hpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Class declaration for ClueBoolRoom, derived from BoolRoom
 * Input: None
 * Output: None
 * *****************************************************************/

#ifndef CLUEBOOLROOM_HPP
#define CLUEBOOLROOM_HPP

#include <string>
#include "BoolRoom.hpp"
using std::string;

class ClueBoolRoom:public BoolRoom
{
private:
	string clue;
public:
	ClueBoolRoom();
	ClueBoolRoom(string, string, string, string, string);
	virtual void interaction();
	void setClue(string);
	string getClue();
};

#endif