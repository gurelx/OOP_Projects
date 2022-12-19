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

#ifndef SDDS_WORD_H 
#define SDDS_WORD_H

const int MAX_DEFINITIONS = 8;
const int MAX_WORD_LEN = 64;
const int  MAX_DEF_LEN = 1024;

struct WordInfo
{
	int defCount; // definiton count
	char type[MAX_DEFINITIONS][MAX_WORD_LEN + 1];
	char definition[MAX_DEFINITIONS][MAX_DEF_LEN + 1];
};

struct Word
{
	char name[MAX_WORD_LEN + 1]; // the word itself
	struct WordInfo wordInfo; // attributes of that word
};

namespace sdds {

	void DisplayWord(const char* word);
	void AddWord(const char* word, const char* type, const char* definition);
	int UpdateDefinition(const char* word, const char* type, const char* definition);
}

#endif