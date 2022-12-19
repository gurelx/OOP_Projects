/*****************************************************************************
                          Workshop - #9
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

#include <iostream>

namespace sdds
{
	class Text
	{
	public:
		//Constructor
		Text();

		// Rule of three
		Text(Text& src);
		void operator=(Text& src);
		~Text();

		// Read & Write
		std::istream& read(std::istream& in);
		virtual std::ostream& write(std::ostream& out) const;

	private:
		char* m_content;

	protected:
		const char& operator[](int index) const;
	};

	// Helpers
	std::istream& operator >> (std::istream& in, Text& text);
	std::ostream& operator << (std::ostream & out, const Text & text);

}
#endif // !SDDS_HTMLTEXT_H
