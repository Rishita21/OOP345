/*================================================================
Name: Rishita Rajendrakumar Patel
ID: 141921205
Email: rrpatel42@myseneca.ca
Section: OOP 345 NBB
Date: 08 Feb 2022
==================================================================*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include "Pair.h"

namespace sdds 
{
    template<class T, size_t CAPACITY>
    class Collection {
    protected:
        T arr[CAPACITY];
        size_t num_elements{ 0 };
        T dummy{};
    public:

        Collection() {}
        virtual ~Collection() {}

        size_t size()
            //a query that returns the current number of elements in the collection....
        {
            return num_elements;
        }

        void display(std::ostream& os = std::cout)const 
        {
            os << "----------------------\n";
            os << "|" << " Collection Content " << "|\n";
            os << "----------------------\n";
            for (size_t i = 0; i < num_elements; i++) 
            {
                os << arr[i] << std::endl;
            }
            os << "----------------------\n";
        }

        virtual bool add(const T& item) 
        {
            bool decider = true;
            // If the item has been added, this function return true....
            if (num_elements < CAPACITY) 
            {
                arr[num_elements] = item;
                num_elements++;
                decider = true;
            }
            else
            {
                decider = false;
            }

            return decider;
        }

        T& operator[](int indx) 
        {
            if (indx >= 0 && (unsigned)indx < num_elements) {
                return arr[indx];
            }
            else
            {
                return dummy;
            }
        }
    };

    template<> Collection<Pair, 100>::Collection() 
    {
        Pair P("No Key", "No Value");
        dummy = P;

    };

}
#endif 
