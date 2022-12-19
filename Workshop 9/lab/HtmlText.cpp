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
#include "HtmlText.h"

using namespace std;

namespace sdds
{
    // Constructor
    HtmlText::HtmlText(const char* title)
    {
        // If argument is not null dynamically allocate and store the value
        if (title) 
        {
            this->m_title = new char[static_cast <int>(strlen(title)) + 1]; // casted from size_t for gcc
            strcpy(this->m_title, title);
        }
        else this->m_title = nullptr; // else set to null
    }

    // Copy constructor
    HtmlText::HtmlText(HtmlText& src)
    {
        this->m_title = nullptr;
        *this = src;
    }

    // Assignment overload
    void HtmlText::operator=(HtmlText& src)
    {

        Text::operator= (src); // call the base operator first
        // If there is content in this
        if (this->m_title)
        {
            delete[] this->m_title;
            this->m_title = nullptr;
        }

        if (this != &src)
        {
            this->m_title = new char[static_cast <int>(strlen(src.m_title)) + 1]; // casted from size_t for gcc
            strcpy(this->m_title, src.m_title);
        }
    }

    // Destructor
    HtmlText::~HtmlText()
    {
        delete[] this->m_title;
        this->m_title = nullptr;
    }

    // Overloaded method
    ostream& HtmlText::write(ostream& out) const
    {
        bool ms = false;
        int i = 0;
        // Head
        out << "<html><head><title>";

        // Title
        if (this->m_title) out << this->m_title;
        else out << "No Title";
        out << "</title></head>\n<body>\n";

        // Header
        if (this->m_title) out << "<h1>" << m_title << "</h1>\n";

        // Content
        while (this->operator[](i))
        {
            // Conversion to html
            switch (this->operator[](i))
            {
            case ' ':
                if (ms) out << "&nbsp;";
                else
                {
                    ms = true;
                    out << ' ';
                }
                break;

            case '<':
                out << "&lt;";
                ms = false;
                break;

            case '>':
                out << "&gt;";
                ms = false;
                break;

            case '\n':
                out << "<br />\n";
                ms = false;
                break;

            default:
                ms = false;
                out << this->operator[](i);
                break;
            }
            i++;
        }
        // Closing tags
        out << "</body>\n</html>";
        return out;
    }

}