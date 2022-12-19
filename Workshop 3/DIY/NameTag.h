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

#ifndef SDDS_NAMETAG_H
#define SDDS_NAMETAG_H

namespace sdds
{
	class NameTag
	{
	public: // public members
		char name[50];
		int nameIndex = 0;

	public: // public methods
		void set(const char* name);
	};
}

#endif