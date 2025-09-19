/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:13:44 by enschnei          #+#    #+#             */
/*   Updated: 2025/09/18 15:43:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    this->_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &src) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_value = src.getRawBits();
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw){
    this->_value = raw;
}