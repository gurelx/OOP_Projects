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

#ifndef SDDS_TAGLIST_H
#define SDDS_TAGLIST_H

namespace sdds
{
	class TagList
	{
	public:
		class NameTag* nptr;
		int numOfTags;

	public: // Public methods
		void set();
		void set(int num);
		void add(const NameTag& nt);
		void print();
		void cleanup();
	};
}

#endif