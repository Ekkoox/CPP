/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:03:16 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/12 16:41:34 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(void)
{
    ScalarConverter::convert("42");
    ScalarConverter::convert("a");
    ScalarConverter::convert("3.14f");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("inf");
    ScalarConverter::convert("2147483648"); // out of int range
    ScalarConverter::convert("non-numeric");
    return (0);
}