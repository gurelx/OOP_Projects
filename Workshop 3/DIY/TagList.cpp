/*
*****************************************************************************
						  Workshop - #3 (P2)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

#include "NameTag.h"
#include "TagList.h"


using namespace sdds;
using namespace std;

// Sets the TagList to an empty state
void sdds::TagList::set()
{
	nptr = nullptr;
	numOfTags = 0;
};

// Calls CleanUp() and then dynamically creates an array of num NameTags.
void sdds::TagList::set(int num)
{
	sdds::TagList::cleanup();
	nptr = new NameTag[num];
	numOfTags = num;
};

// Adds up to num (of the set method) NameTags to the TagList.
void sdds::TagList::add(const NameTag& nt)
{
	std::strcpy(nptr[nptr->nameIndex].name, nt.name);
	nptr->nameIndex++;
};

// Prints all the tags with the same size that is the frame size of the longest name in the list.
void sdds::TagList::print()
{
	unsigned int longestName = 0;

	// Find the size of the longest name
	for (int i = 0; i < numOfTags; i++)
	{
		if (std::strlen(nptr[i].name) > longestName)
		{
			longestName = std::strlen(nptr[i].name);
		}
	}

	// Print all
	for (int i = 0; i < numOfTags; i++)
	{
		std::cout << std::string(longestName + 4, '*') << std::endl;
		std::cout << "* " << nptr[i].name 
			<< std::string(longestName - std::strlen(nptr[i].name), ' ') << " *" << std::endl;
		std::cout << std::string(longestName + 4, '*') << std::endl;
	}
};

// Deallocates the NameTags and put the TagList back to a safe empty state.
void sdds::TagList::cleanup()
{
	delete[] nptr;
	sdds::TagList::set();
};

