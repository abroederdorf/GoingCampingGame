/********************************************************************
 * Program Filename: inputValiation.cpp 
 * Author: Alicia Broederdorf
 * Date: April 18, 2015
 * Description: This program defines the functions to validate an
 * integer and double value. It also contains functions to convert
 * strings to an integer or double
 * Input: None
 * Output: None
 * *****************************************************************/
 
#include <iostream>
#include <string>
#include <cstdlib>
#include "inputValidation.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;

/****************
* Function Name: intValidate
* Description: This function will validate the input is an integer value
* Parameters: string input is the provided input
* Pre-Conditions: None
* Post-Conditions: None
****************/
bool intValidate(string input)
{
	int total = 0;
	bool status = true;

	//Check that all string characters are digits
	for (int i = 0; i < input.length(); i++)
	{
		if (!(isdigit(input.at(i))))
			total++;
	}
	
	//Set status to false if characters other than digits were found
	if (total != 0)
		status = false;

	return status;
}

/****************
* Function Name: dblValidate
* Description: This function will validate the input is a double value
* Parameters: string input is the provided input
* Pre-Conditions: None
* Post-Conditions: None
****************/
bool dblValidate(string input)
{
	int total = 0, period = 0;
	bool status = true;

	//Check to see if each character is digit or period, and add up
	//number of periods found
	for (int i = 0; i < input.length(); i++)
	{
		if (!(isdigit(input.at(i)) || input.at(i) == '.'))
			total++;
		if (input.at(i) == '.')
		{
			period++;
			if (period > 1)
				total++;
		}
	}

	//Set status to false if characters other than digits or more than one
	//period was found
	if (total != 0)
		status = false;

	return status;
}

/****************
* Function Name: strToInt
* Description: This function will convert a string to an integer
* Parameters: string input is the provided input to be converted
* Pre-Conditions: None
* Post-Conditions: None
****************/
int strToInt(string input)
{
	char inputChar[50] = {0};

	//Convert string to c-string
	for (int i = 0; i < input.length(); i++)
		inputChar[i] = input.at(i);

	//Return converted c-string to integer
	return atoi(inputChar);
}

/****************
* Function Name: strToDbl
* Description: This function will convert a string to a double
* Parameters: string input is the provided input to be converted
* Pre-Conditions: None
* Post-Conditions: None
****************/
double strToDbl(string input)
{
	char inputChar[50] ={0};
	
	//Convert string to c-string
	for (int i = 0; i < input.length(); i++)
		inputChar[i] = input.at(i);

	//Return converted c-string to integer
	return atof(inputChar);
}

/*
//Test program
int main()
{
	string input[4];

	for (int i = 0; i < 4; i++)
	{
		//Prompt for values
		cout << "\n\nPlease enter value " << i + 1 << ": ";
		cin >> input[i];

		//Validate integer and print value or error
		if (intValidate(input[i]))
			cout << "\nValue " << i + 1 << " converted is: " << strToInt(input[i]);
		else
			cout << "\nValue " << i + 1 << " is not an integer.";

		//Validate double and print value or error
		if (dblValidate(input[i]))
			cout << "\nValue " << i + 1 << " converted is: " << strToDbl(input[i]);
		else
			cout << "\nValue " << i + 1 << " is not a double.";
	}
	
	cout << endl;
	return 0;
}*/
