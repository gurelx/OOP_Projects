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

// Sets the name, held by the NameTag object
void sdds::NameTag::set(const char* name)
{
	strcpy(this->name, name);
}
