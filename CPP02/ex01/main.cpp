/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:38:57 by enschnei          #+#    #+#             */
/*   Updated: 2025/09/19 13:38:57 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main (void) {

    // Mandatory test
    
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    // Personal test

    std::cout << "=========================== Personal test ===========================" << std::endl;
    
    Fixed e(-10);
    Fixed f(-42.42f);

    std::cout << "e is " << e << std::endl;
    std::cout << "f is " << f << std::endl;
    std::cout << "e as int: " << e.toInt() << std::endl;
    std::cout << "f as int: " << f.toInt() << std::endl;
    std::cout << "e as float: " << e.toFloat() << std::endl;
    std::cout << "f as float: " << f.toFloat() << std::endl;


    return (0);
}