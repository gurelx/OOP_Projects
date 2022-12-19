/*
*****************************************************************************
						  Workshop - #2 (P2)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

struct Data
{
	char postalCode[3];
	int population;
};

namespace sdds {

	bool load(const char filename[]);
	void sort(Data* rep, int size);
	void display();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_