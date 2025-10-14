/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:14:42 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/14 16:33:15 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed           a;
    Fixed const     b(Fixed(5.05f) * Fixed(2));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "=========================== Personal test ===========================" << std::endl;

    Fixed   c(10);
    Fixed   d(42.42f);
    
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "c + d = " << c + d << std::endl
                << "c - d = " << c - d << std::endl
                << "c * d = " << c * d << std::endl
                << "d / c = " << d / c << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;
    std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
    std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
    
    return (0);
}