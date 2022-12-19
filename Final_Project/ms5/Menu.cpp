/************************************************************
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Gurel Sezgin
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/7  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Menu.h"

namespace sdds
{
	/**** MenuItem Methods ****/

	// Constructor
	MenuItem::MenuItem(const char* item)
	{
		if (item != nullptr)
		{
			this->m_itemName[0] = '\0';
			std::strncpy(this->m_itemName, item, MAX_NAME);
		}
		else
		{
			this->m_itemName[0] = '\0';
		}
	}

	// Sets menu item to empty
	void MenuItem::setItemEmpty()
	{
		this->m_itemName[0] = '\0';
	}

	// Display itself by writing its content on the screen and printing a new line
	std::ostream& MenuItem::displayItem(std::ostream& out) const
	{
		out << this->m_itemName << std::endl;
		return out;
	}

	/**** Menu Methods ****/

	// Constructor
	Menu::Menu(const char* title, int indent)
	{
		if (title == nullptr)
		{
			this->clear();
		}
		else
		{
			this->m_title[0] = '\0';
			std::strncpy(this->m_title, title, MAX_NAME);

			(indent > 0) ? this->m_indent = indent : this->m_indent = 0; // check if indent has been passed < 0
			for (int i = 0; i < MAX_NO_OF_ITEMS; i++)
			{
				this->m_items[i].setItemEmpty();
			}
			this->m_itemNumber = 0;
		}
	}

	/** Manipulation methods **/

	// Set menu to an invalid empty state
	void Menu::clear()
	{
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++)
		{
			this->m_items[i].m_itemName[0] = '\0';
		}
		this->m_title[0] = '\0';
		this->m_itemNumber = 0;
		this->m_indent = 0;
	}

	// Add a menu item if possible
	void Menu::add(const char* item)
	{
		if (item == nullptr)
		{
			this->clear();
		}
		else
		{
			// If Menu is not invalid or full (bool operator did not work as bool(this) here !)
			if (bool(this) && this->m_itemNumber < MAX_NO_OF_ITEMS)
			{
				this->m_items[this->m_itemNumber].m_itemName[0] = '\0';
				std::strncpy(this->m_items[this->m_itemNumber].m_itemName, item, MAX_NAME);
				this->m_itemNumber++;
			}
		}
	}
	// To set the indentation
	void Menu::setMenuIndent(const int indent)
	{
		if (indent > 0)
		{
			this->m_indent = indent;
		}
	}

	/** Cast & operator overloads **/

	// Returns true if the Menu is valid and usable
	Menu::operator bool() const
	{
		return bool(this->m_title[0]);
	}

	// Integer cast returns run function
	Menu::operator int() const
	{
		return this->run();
	}

	// Insert a constant character C-string into the Menu as a MenuItem
	Menu& Menu::operator<<(const char* item)
	{
		this->add(item);
		return *this;
	}

	// A string can be assigned to the title
	Menu& Menu::operator=(const char* src)
	{
		if (src == nullptr) this->clear();
		else
		{
			std::strncpy(this->m_title, src, MAX_NAME);
		}
		return *this;
	}

	/** Displaying & Running **/

	// Display itself 
	std::ostream& Menu::display(std::ostream& out) const
	{
		if (this->isEmpty())
		{
			out << "Invalid Menu!" << std::endl;
		}
		else if (!this->m_items[0].m_itemName[0])
		{
			if (this->m_title[0])
			{
				out << this->m_title << std::endl; // If there is a title display it
			}
			out << "No Items to display!" << std::endl;
		}
		else
		{
			// Without indentation
			if (!this->m_indent)
			{
				out << this->m_title << std::endl;

				for (int i = 0; i < this->m_itemNumber; i++)
				{
					out << i + 1 << "- ";
					this->m_items[i].displayItem();
				}
				out << "> ";
			}
			// With indentation
			else
			{
				out << std::string(this->m_indent * 4, ' ') << this->m_title << std::endl;

				for (int i = 0; i < this->m_itemNumber; i++)
				{
					out << std::string(this->m_indent * 4, ' ') << i + 1 << "- ";
					this->m_items[i].displayItem();
				}
				out << std::string(this->m_indent * 4, ' ') << "> ";
			}
		}
		return out;
	}

	// Displays the menu items and prompts user for selection
	int Menu::run() const
	{
		int selection = 0;
		this->display();
		if (this->m_items[0].m_itemName[0])
		{

			std::cin >> selection;
			while (!selection || selection > this->m_itemNumber || std::cin.fail())
			{
				if (std::cin.fail())
				{
					std::cout << "Invalid Integer, try again: ";
				}
				else
				{
					std::cout << "Invalid selection, try again: ";
				}
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cin >> selection;
			}
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		return selection;
	}

	// Returns true if the Menu is in an invalid empty State (bool operator did not work as bool(this) here !)
	bool Menu::isEmpty() const
	{
		return bool(!this->operator bool());
	}
}