/********************************************************************
 * Program Filename: Room.hpp
 * Author: Alicia Broederdorf
 * Date: May 31, 2015
 * Description: Class declaration for Room
 * Input: None
 * Output: None
 * *****************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
using std::string;

enum essentials {MAP, COMPASS, SUNGLASSES, JACKET, HEADLAMP, FIRSTAID, FIRESTARTER, MATCHES, KNIFE, SNICKERSBAR, EMPTY};

class Room
{
protected:
	string name;
	string type;
	Room *north;
	Room *south;
	Room *east;
	Room *west;
public:
	Room()
	{
		name = "";
		type = "";
		north = NULL;
		south = NULL;
		east = NULL;
		west = NULL;
	}
	Room(string iName, string iType)
	{
		name = iName;
		type = iType;
		north = NULL;
		south = NULL;
		east = NULL;
		west = NULL;
	}
	virtual void printStatus() = 0;
	virtual void interaction() = 0;
	void setName(string);
	string getName();
	void setType(string);
	string getType();
	void setNorth(Room *);
	Room * getNorth();
	void setSouth(Room *);
	Room * getSouth();
	void setEast(Room *);
	Room * getEast();
	void setWest(Room *);
	Room * getWest();
};

#endif