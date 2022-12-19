/*****************************************************************************
                          Workshop - #6 (P2)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#include <iostream>
#include <iomanip>
#include "Basket.h"

namespace sdds {

    // Deallocates existing memory and sets everything empty
    void Basket::setEmpty() 
    {
        if (m_fruits != nullptr)
        {
            delete[] m_fruits;
        }
        m_fruits = nullptr;
        m_basketSize = 0;
        m_price = 0;
    }

    // Default constructor
    Basket::Basket()
    {
        setEmpty();
    }

    // Stores the parameters into the attributes if all the parameters are valid
    Basket::Basket(Fruit* fruits, int size, double price)
    {
        if ((fruits != nullptr && size > 0 && price > 0))
        {
            setEmpty();
            m_fruits = new Fruit[size];

            for (int i = 0; i < size; i++)
            {
                m_fruits[i] = fruits[i];
            }
            m_basketSize = size;
            m_price = price;
        }
    }

    // Assigns src to *this
    Basket::Basket(const Basket& src)
    {
        setEmpty();
        *this = src;
    }

    // Set *this to another basket
    Basket& Basket::operator=(const Basket& src)
    {
        if (this != &src)
        {
            setEmpty(); // starting with safe empty state

            // Allocates new memory pointed by m_fruits to the number of the values in the object that is being copied.
            if (src.m_fruits != nullptr)
            {
                this->m_fruits = new Fruit[src.m_basketSize];

                // All fruits in the object are being copied into the newly allocated memory.
                for (int i = 0; i < src.m_basketSize; i++)
                {
                    this->m_fruits[i] = src.m_fruits[i];
                }
                // Basket size has also changed
                this->m_basketSize = src.m_basketSize;
                this->m_price = src.m_price;
            }
        }
        return *this;
    }

    // Deconstructor
    Basket::~Basket()
    {
        delete[] m_fruits;
        m_fruits = nullptr;
    }

    // Check if basket is empty
    bool Basket::isEmpty() const
    {
        return bool(m_fruits == nullptr);

    }

    // Updates the price attribute to the value received as parameter
    void Basket::setPrice(double price)
    {
        m_price = price;
    }

    // Returns whather there are fruits in the basket
    Basket::operator bool()
    {
        return bool(m_fruits != nullptr && m_basketSize > 0);
    }

    // Add a new fruit object to the basket
    Basket& Basket::operator+=(Fruit fruit)
    {
        Fruit* tmpPtr = new Fruit[m_basketSize + 1]; // temp with a bigger memory

        for (int i = 0; i < m_basketSize; i++)
        {
            tmpPtr[i] = m_fruits[i]; // append this->fruits to temp
        }

        tmpPtr[m_basketSize] = fruit; // append fruit to extra memory
        m_basketSize++; // basketsize has increased
        delete[] m_fruits;
        m_fruits = tmpPtr; // this should point to temp
        return *this;
    }

    // Returns the basket size
    int Basket::countBasket() const
    {
        return m_basketSize;
    }

    // Prints the fruits, the quantity, and the price one by one
    void Basket::printFruits(std::ostream& os) const
    {
        
        for (int i = 0; i < m_basketSize; i++)
        {
            os.setf(std::ios::right);
            os << std::setw(10) << m_fruits[i].m_name << ": ";
            os.setf(std::ios::fixed);
            os.precision(2);
            os << m_fruits[i].m_qty << "kg" << std::endl;
        }
        os << "Price: " << m_price << std::endl;
    }

    // Helper function
    std::ostream& operator<<(std::ostream& os, const Basket& B)
    {
        if (B.isEmpty())
        {
            os << "The basket is empty!" << std::endl;
        }
        else
        {
            os << "Basket Content:" << std::endl;
            B.printFruits(os);
        }
        return os;
    }
}