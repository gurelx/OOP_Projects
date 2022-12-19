/*****************************************************************************
                          Workshop - #9
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H

#include "Text.h"

namespace sdds 
{
	class HtmlText: public Text
	{
	public:
		// Constructor
		HtmlText(const char* title = nullptr);

		// Rule of three
		HtmlText(HtmlText& src);
		void operator= (HtmlText& src);
		~HtmlText();

		std::ostream& write(std::ostream& out) const;

	private:
		char* m_title;
	};
}
#endif // !SDDS_HTMLTEXT_H
