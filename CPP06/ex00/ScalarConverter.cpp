/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:07:50 by enschnei          #+#    #+#             */
/*   Updated: 2025/12/05 12:52:57 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{
    return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) 
{
    (void)src;
    return ;
}

ScalarConverter::~ScalarConverter() 
{
    return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) 
{
    (void)rhs;
    return (*this);
}

static int find_type(const std::string &literal)
{
    size_t  i = 0;
    int     dot_count = 0;
    int     f_count = 0;

    // single non-digit char -> char
    if (literal.length() == 1 && !isdigit(literal[0]))
        return (0); // char

    // special literals: float-suffix (nanf, inff) -> float
    if (literal == "-inff" || literal == "+inff" || literal == "inff" || literal == "nanf")
        return (2); // float special cases

    // special literals: no-suffix (nan, inf) -> double
    if (literal == "-inf" || literal == "+inf" || literal == "inf" || literal == "nan")
        return (3); // double special cases

    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
            dot_count++;
        else if (literal[i] == 'f' && i == literal.length() - 1)
            f_count++;
        else if (!isdigit(literal[i]))
            return (-1);
    }
    if (dot_count == 0 && f_count == 0)
        return (1); // int
    else if (dot_count == 1 && f_count == 1)
        return (2); // float
    else if (dot_count == 1 && f_count == 0)
        return (3); // double
    return (-1);
}

static void convert_char(const std::string &literal)
{
    char    c = literal[0];
    int     i = static_cast<int>(c);
    float   f = static_cast<float>(c);
    double  d = static_cast<double>(c);

    std::cout << CYAN << "Char: '" << c << "'" << RESET << std::endl;
    std::cout << "Int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Float: " << f << "f" << std::endl;
    std::cout << "Double: " << d << std::endl;
}

static void convert_int(const std::string &literal)
{
    long    l = std::strtol(literal.c_str(), NULL, 10);
    if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
    {
        std::cerr << RED << "Error: Integer overflow." << RESET << std::endl;
        return ;
    }
    int     i = static_cast<int>(l);
    char    c = static_cast<char>(i);
    float   f = static_cast<float>(i);
    double  d = static_cast<double>(i);

    if (isprint(c))
        std::cout << "Char: '" << c << "'" << std::endl;
    else if (i >= 0 && i <= 127)
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: Impossible" << std::endl;
    std::cout << CYAN << "Int: " << i << RESET << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Float: " << f << "f" << std::endl;
    std::cout << "Double: " << d << std::endl;
}

static void convert_float(const std::string &literal)
{
    float   f = std::strtof(literal.c_str(), NULL);
    int     i = static_cast<int>(f);
    char    c = static_cast<char>(i);
    double  d = static_cast<double>(f);

    if (isprint(c))
        std::cout << "Char: '" << c << "'" << std::endl;
    else if (i >= 0 && i <= 127)
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: Impossible" << std::endl;
    if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max() || literal == "nan" || literal == "nanf")
        std::cout << "Int: Impossible" << std::endl;
    else
        std::cout << "Int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << CYAN <<"Float: " << f << "f" << RESET << std::endl;
    std::cout << "Double: " << d << std::endl;
}

static void convert_double(const std::string &literal)
{
    double  d = std::strtod(literal.c_str(), NULL);
    int     i = static_cast<int>(d);
    char    c = static_cast<char>(i);
    float   f = static_cast<float>(d);

    if (isprint(c))
        std::cout << "Char: '" << c << "'" << std::endl;
    else if (i >= 0 && i <= 127)
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: Impossible" << std::endl;
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || literal == "nan" || literal == "nanf")
        std::cout << "Int: Impossible" << std::endl;
    else
        std::cout << "Int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Float: " << f << "f" << std::endl;
    std::cout << CYAN << "Double: " << d << RESET << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (find_type(literal) == 0)
        convert_char(literal);
    else if (find_type(literal) == 1)
        convert_int(literal);
    else if (find_type(literal) == 2)
        convert_float(literal);
    else if (find_type(literal) == 3)
        convert_double(literal);
    else
        std::cerr << RED << "Error: Invalid literal format." << RESET << std::endl;
}
