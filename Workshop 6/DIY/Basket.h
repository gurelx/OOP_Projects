/*****************************************************************************
                          Workshop - #6 (P2)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_
#include <iostream>

namespace sdds
{
    struct Fruit
    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket
    {
    private:
        // if I don't initialize members matrix gives errors
        Fruit* m_fruits = nullptr; 
        int m_basketSize = 0;
        double m_price = 0;
        void setEmpty(); // set to an empty state

    public:
        // Constructors
        Basket();
        Basket(Fruit* fruits, int size, double price);
        Basket(const Basket&);
        Basket& operator=(const Basket&);

        ~Basket();
        bool isEmpty() const; // checks if object is empty
        void setPrice(double price);
        operator bool(); // are there any fruits in the basket?
        Basket& operator +=(Fruit fruit);

        int countBasket() const; // return basket size
        void printFruits(std::ostream& os) const; // Prints the fruits, the quantity, and the price one by one
    };

    // Helper function
    std::ostream& operator<<(std::ostream& os, const Basket& B);
}

#endif