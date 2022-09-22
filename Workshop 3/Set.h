/*================================================================
Name: Rishita Rajendrakumar Patel
ID: 141921205
Email: rrpatel42@myseneca.ca
Section: OOP 345 NBB
Date: 08 Feb 2022
==================================================================*/

#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>
#include <cmath>
#include <string>

#include "Pair.h"
#include "Collection.h"

namespace sdds 
{
    template<class T>
    class Set : public Collection<T, 100> 
    {
        const size_t CAPACITY = 100;

    public:
        Set()
        {
            ;
        }

        bool add(const T& item) 
        {
            for (int i = 0; (unsigned)i < this->num_elements; i++)
            {
                if (item == this->arr[i])
                {
                    return false;
                }
            }
            return Collection<T, 100>::add(item);
        }
    };

    template<>
    bool Set<double>::add(const double& item) 
    {

        for (int i = 0; (unsigned)i < this->num_elements; i++)
        {
            if (std::fabs(item - this->arr[i]) <= 0.01)
            {
                return false;
            }
        }

        return Collection<double, 100>::add(item);
    };
}
#endif // !
