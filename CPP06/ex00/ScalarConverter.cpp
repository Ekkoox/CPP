/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:07:50 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/12 17:54:22 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

void ScalarConverter::convert(const std::string &literal)
{
    char    c;
    int     i;
    float   f;
    double  d;
    char*   end;

    // --- CHAR ---
    end = NULL;
    i = std::strtol(literal.c_str(), &end, 10);
    if (*end == '\0' && i >= 0 && i <= 127)
    {
        c = static_cast<char>(i);
        if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;

    // --- INT ---
    end = NULL;
    i = std::strtol(literal.c_str(), &end, 10);
    if (*end == '\0')
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    // --- FLOAT ---
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        std::cout << "float: " << literal << std::endl;
    else
    {
        end = NULL;
        f = std::strtof(literal.c_str(), &end);
        if (*end == '\0' || *end == 'f')
            std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
        else
            std::cout << "float: impossible" << std::endl;
    }

    // --- DOUBLE ---
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        std::cout << "double: " << literal << std::endl;
    else
    {
        end = NULL;
        d = std::strtod(literal.c_str(), &end);
        if (*end == '\0' || *end == 'f')
            std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
        else
            std::cout << "double: impossible" << std::endl;
    }
}
