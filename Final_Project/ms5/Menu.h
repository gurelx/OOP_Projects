/************************************************************
Final Project Milestone 5
Module: Menu
Filename: Menu.h
Version 1.0
Author	Gurel Sezgin
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/7  Preliminary release
2022/11/8  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
************************************************************/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>

namespace sdds
{
	// Globals
	const int MAX_NO_OF_ITEMS = 10;
	const int MAX_NAME = 50;

	class Menu; // Declare menu first

	class MenuItem
	{
	private:
		char m_itemName[MAX_NAME + 1];

		// Constructors
		MenuItem(const char* item = nullptr);

		std::ostream& displayItem(std::ostream & = std::cout) const;
		void setItemEmpty();

		// Copy preventation
		MenuItem(const MenuItem&) = delete;
		void operator=(const MenuItem&) = delete;

		friend class Menu;
	};

	class Menu
	{
	public:
		// Constructors
		Menu(const char* title = nullptr, int indent = 0);

		// Manipulation methods
		void clear();
		void add(const char* item);
		void setMenuIndent(const int indent); // To set the indentation

		// Cast & operator overloads
		operator bool() const;
		operator int() const;
		Menu& operator<<(const char* item);
		Menu& operator=(const char* title);

		// Running & Displaying
		std::ostream& display(std::ostream& out = std::cout) const;
		int run() const;

		bool isEmpty() const; // This method has been moved to public since it has been used by parking

	private:
		char m_title[MAX_NAME + 1];
		MenuItem m_items[MAX_NO_OF_ITEMS];
		int m_itemNumber;
		int m_indent;

		// Copy preventation
		Menu(const Menu&) = delete;
		void operator=(const Menu&) = delete;

	};
}
#endif // !SDDS_MENU_H
