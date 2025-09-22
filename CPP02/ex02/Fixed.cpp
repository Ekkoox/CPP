/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:22:44 by enschnei          #+#    #+#             */
/*   Updated: 2025/09/22 19:01:27 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_value = 0;
}

Fixed::Fixed(const int int_value)
{
    this->_value = int_value << this->_fractionalBits;
}

Fixed::Fixed(const float float_value)
{
    this->_value = roundf(float_value * (1 << this->_fractionalBits));
}


Fixed::Fixed(const Fixed &src)
{
    *this = src;
}
Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &src)
{
    if (this != &src)
        this->_value = src.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_value / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->_value >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return (this->_value > rhs._value);
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->_value < rhs._value);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->_value >= rhs._value);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->_value <= rhs._value);
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->_value == rhs._value);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->_value != rhs._value);
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits(this->_value + rhs._value);
    return (result);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits(this->_value - rhs._value);
    return (result);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    Fixed result;
    long tmp = (long)this->_value * (long)rhs._value;
    result.setRawBits((int)(tmp >> this->_fractionalBits));
    return (result);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    Fixed result;
    if (rhs._value == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return (result);
    }
    long tmp = ((long)this->_value << this->_fractionalBits) / (long)rhs._value;
    result.setRawBits((int)tmp);
    return (result);
}

Fixed &Fixed::operator++(void) // Prefix increment
{
    this->_value++;
    return (*this);
}

Fixed Fixed::operator++(int) // Postfix increment
{
    Fixed temp(*this);
    this->_value++;
    return (temp);
}

Fixed &Fixed::operator--(void) // Prefix decrement
{
    this->_value--;
    return (*this);
}

Fixed Fixed::operator--(int) // Postfix decrement
{
    Fixed temp(*this);
    this->_value--;
    return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}
