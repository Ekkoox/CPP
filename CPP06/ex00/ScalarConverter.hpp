#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>


class ScalarConverter
{
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &rhs);    

    public :
        static void    convert(const std::string &literal);

};

#endif