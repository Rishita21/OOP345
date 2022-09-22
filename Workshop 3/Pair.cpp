/*================================================================
Name: Rishita Rajendrakumar Patel
ID: 141921205
Email: rrpatel42@myseneca.ca
Section: OOP 345 NBB
Date: 08 Feb 2022
==================================================================*/

#include "Pair.h"
using namespace std;
namespace sdds 
{
    bool Pair::sameKey(const Pair& P1, const Pair& P2) 
    {
        //Two objects of type Pair are considered to be equal if they have the same key....
        bool decider = false;
        if (P1.m_key == P2.m_key) 
        {
            decider = true;
        }
        else
        {
            decider = false;
        }
        return decider;
    }

    std::ostream& Pair::display(std::ostream& os) const 
    {
        os.width(20);
        os.setf(ios::right);
        os << getKey();
        os.setf(ios::left);
        os << ": " << getValue();

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Pair& P) 
    {
        return P.display(os);
    }
}
