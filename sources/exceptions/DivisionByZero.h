#ifndef DIVISIONBYZERO_H
#define	DIVISIONBYZERO_H

#include <stdexcept>
#include <string>

class DivisionByZero : public std::logic_error
{
public:
    DivisionByZero()
        :logic_error("Division by zero is not accepted.")
    {}
    
    DivisionByZero(const std::string& error_message)
        :logic_error(error_message)
    {}
};

#endif	/* DIVISIONBYZERO_H */

