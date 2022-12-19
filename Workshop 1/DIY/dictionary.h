/*
*****************************************************************************
						  Workshop - #1 (P2)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_DICTIONARY_H 
#define SDDS_DICTIONARY_H

#include "word.h"

const int MAX_WORD = 100;

struct Dictionary {

	struct Word words[MAX_WORD]; // there are multiple words in the dictionary
	int wordCount; // the word count
};

namespace sdds {

	int LoadDictionary(const char* filename);
	void SaveDictionary(const char* filename);
}

extern Dictionary dictionary; // global dictionary

#endif