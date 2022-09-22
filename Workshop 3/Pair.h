/*================================================================
Name: Rishita Rajendrakumar Patel
ID: 141921205
Email: rrpatel42@myseneca.ca
Section: OOP 345 NBB
Date: 08 Feb 2022
==================================================================*/

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
#include <string>

namespace sdds 
{
    class Pair {
        std::string m_key{};
        std::string m_value{};
    public:
        const std::string& getKey() const { return m_key; }
        const std::string& getValue() const { return m_value; }
        Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};

        // TODO: Add here the missing the prototypes for the members
    //           that are necessary if this class is to be used
    //           with the template classes described below.
    //       Implement them in the Pair.cpp file.
        static bool sameKey(const Pair& P1, const Pair& P2);

        Pair() : m_key{ "" }, m_value{ "" }{};

        virtual std::ostream& display(std::ostream& os = std::cout) const;

        bool operator==(const Pair& P)const 
        {
            return m_key == P.getKey();
        }

    };
    std::ostream& operator<<(std::ostream& os, const Pair& P);
}
#endif // !SDDS_PAIR_H
