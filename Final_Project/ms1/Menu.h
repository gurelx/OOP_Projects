/************************************************************
Final Project Milestone 1
Module: Menu
Filename: Menu.h
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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>

namespace sdds 
{
	const int MAX_NO_OF_ITEMS = 10;
	const int MAX_NAME = 50;

	class Menu;

	class MenuItem
	{
	private:
		char m_itemName[MAX_NAME + 1];
		MenuItem() = default;
		MenuItem(const char* item);
		std::ostream& displayItem(std::ostream& = std::cout) const;
		void setItemEmpty();
		MenuItem(const MenuItem&) = delete;
		void operator=(const MenuItem&) = delete;

		friend class Menu;
	};

	class Menu
	{
	private:
		char m_title[MAX_NAME + 1];
		MenuItem m_items[MAX_NO_OF_ITEMS];
		int m_itemNumber;
		int m_indent;
		Menu(const Menu&) = delete;
		void operator=(const Menu&) = delete;
		bool isEmpty() const;

	public:
		Menu(const char* title, int indent = 0);
		operator bool() const;
		void clear();
		std::ostream& display(std::ostream& out = std::cout) const;
		Menu& operator=(const char* title);
		void add(const char* item);
		int run() const;
		operator int() const;  
		Menu& operator<<(const char* item);
	};
}
#endif // !SDDS_MENU_H
