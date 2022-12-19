/*****************************************************************************
                          Workshop - #9
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Text.h"

using namespace std;

namespace sdds
{
	unsigned getFileLength(istream& is) {
		unsigned len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, ios::end);
			// tell what is the positions (end position = size)
			len = unsigned(is.tellg());
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}

	// Constructor
	Text::Text()
	{
		this->m_content = nullptr;
	}

	// Copy constructor
	Text::Text(Text& src)
	{
		this->m_content = nullptr;
		*this = src;
	}
	
	// Assignment overload
	void Text::operator=(Text& src)
	{
		// If there is content in this
		if (this->m_content)
		{
			delete[] this->m_content;
			this->m_content = nullptr;
		}

		if (this != &src)
		{
			this->m_content = new char[strlen(src.m_content) + 1];
			strcpy(this->m_content, src.m_content);
		}
	}

	// Destructor
	Text::~Text()
	{
		delete[] this->m_content;
		this->m_content = nullptr;
	}

	// Read file
	istream& Text::read(istream& in)
	{
		int len = static_cast<int>(getFileLength(in)); // casted from unsigned int to get the length
		// Deallocate & reallocate memory
		if (this->m_content) delete[] this->m_content;
		this->m_content = new char[len +1];
		this->m_content[0] = '\0';

		char c;
		int i = 0;
		// While getting the char
		while (in.get(c)) {
			this->m_content[i] = c; // Assign it to content
			i++;
		}
		// making sure to have the last element is the end of content
		this->m_content[i] = '\0'; 

		// If any file read, clear in
		if (this->m_content[0])
		{
			in.clear();
		}
		return in;
	}

	// Write out content
	ostream& Text::write(ostream& out) const
	{
		if (this->m_content)
		{
			out << this->m_content;
		}
		return out;
	}

	// Insertion overload
	istream& operator >> (istream& in, Text& text)
	{
		text.read(in);
		return in;
	}

	// Extraction overload
	ostream& operator << (ostream& out, const Text& text)
	{
		text.write(out);
		return out;
	}
	
	// Provide read only access to the derived class
	const char& Text::operator[](int index) const
	{
		// If index is out of bounds just return the first index
		if (index > static_cast<int>(strlen(this->m_content))) index = 0; // casted from size_t for gcc

		return this->m_content[index];
	}
}