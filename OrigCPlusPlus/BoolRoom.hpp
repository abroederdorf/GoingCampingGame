/********************************************************************
 * Program Filename: BoolRoom.hpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Class declaration for BoolRoom, derived from Room
 * Input: None
 * Output: None
 * *****************************************************************/

#ifndef BOOLROOM_HPP
#define BOOLROOM_HPP

#include <string>
#include "Room.hpp"
using std::string;

class BoolRoom:public Room
{
protected:
	bool status;
	string statusTrue;
	string statusFalse;
	string prompt;
public:
	BoolRoom();
	BoolRoom(string, string, string, string, string);
	virtual void printStatus();
	virtual void interaction();
	void setStatus(bool);
	bool getStatus();
	void setStatusTrue(string);
	string getStatusTrue();
	void setStatusFalse(string);
	string getStatusFalse();
	void setPrompt(string);
	string getPrompt();
};

#endif